#include "Completecrosslinkedlist .h"
#include <stdlib.h> 
#include<stdio.h>
#include <string.h>


/*
��ʼ��M(Crosslist�������ͱ���������г�ʼ��)
���򴴽������ƾ����д�)
*/
int InitSMatrix(CrossList *M)
{
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}


/*����ϡ�����
  Crosslist *M:�ṹ��ָ��;
  ����ָ��ṹ������ı�����Ա��mu/nu/tu/rhead/chead
  (*)M.mu = = M->mu
  �ͷ�����ͷָ��ĵ�ַ�ڴ�ռ䣬ʹ������ڴ��ػ�����
  �ͷ��ڴ�󣬽���ͷ��ָ���Լ�������������Ԫ�����ĵĳ�ʼ��
*/
int DestroySMatrix(CrossList *M)
{
	int i;
	OLNode *p, *q;//ָ�����ã�ָ����(Ԫ��)��ַ

	for (i = 1; i <= (*M).mu; i++) // �����ͷŽ�� 
	{
		p = *((*M).rhead + i);//�����i��ͷָ���ַ
		while (p)
		{
			q = p;
			p = p->right;
			free(q);
		}
	}
	free((*M).rhead);
	free((*M).chead);
	(*M).rhead = (*M).chead = NULL;
	(*M).mu = (*M).nu = (*M).tu = 0;
	return 1;
}



/*
����CreateSMatrix����������ϡ�����ʹ��ʮ������ķ�ʽ�洢����
  ��Ҫ�û���������,������ȷֵ֮����Ҫ����ͷָ�������(*M).rhead
  (*M).chead
*/

void CreateSMatrix(CrossList *M, const char *path)
{
	int k,i;
	int NotZeroNum = 0;
	OLNode *p, *q;//ָ��OLNode���͵�ָ��p��q
	if ((*M).rhead)//�ж�ϡ����������ͷָ���Ƿ�Ϊ��
		DestroySMatrix(M);
	/*
	�����С���ͷָ�������
	OLink*:ָ�����ͣ���������MaxRow����ÿһ����ָ��OLink���͵ı���
	�������ŵ���һ��ָ��OLNode���͵�ָ���ַ
	*/
	(*M).rhead = (OLink*)malloc(sizeof(OLink));
	if (!(*M).rhead)
		exit(0);
	(*M).chead = (OLink*)malloc(sizeof(OLink));
	if (!(*M).chead)
		exit(0);
	/*������������������ͷ�����ʼ����
	����Ĳ�����̵�����һ���ж������������ǵ�ֵΪNULL�������л��Ǹ���û�н��
	*/
	
		(*M).rhead[0] = NULL;
		(*M).chead[0] = NULL;

	/*��ʼ���󣬽���һ������������������(�洢��������Ԫ��ֵ��������Ԫ��)�������г�ʼ��*/
	int **buf=NULL;
	char line[100];
	FILE * pFile;
	int irow = 0;
	int icol = 0;
	int colNum = 0;

	buf = (int **)malloc(sizeof(int*));
	buf[0] = (int *)malloc(sizeof(int));
	//buf[0] = NULL;




	/*��ν��ж�ȡ����*/
	pFile = fopen(path, "r");
	if (pFile != NULL)
	{
		while (1)
		{
			if (fgets(line, 300, pFile) == NULL) 
				break;

			/*�ָ�ÿ��*/
			char *pch = strtok(line, "	");//������ǿգ���ʹ��strtok�������տո�����֣�����һ���ַ���ָ��

			while (pch != NULL)
			{
				int val = atoi(pch);

				/*�洢����,������Ԫ�ض����ڻ��������*/
				buf[irow][icol] = val;
				if (val != 0)
				{
					p = (OLNode*)malloc(sizeof(OLNode));
					if (!p)
						exit(0);
					/* ���ɽ��*/
					p->i = irow;
					p->j = icol;
					p->e = val;
					/*printf("i:%d", p->i);
					printf("j:%d", p->j);
					printf("e:%d", p->e);
					printf("\n");*/

					/*���ɽ���Ҫ����һ����ͷָ��������һ����Ϊ0��Ԫ����������
					 �ж���ͷָ�롢��ͷָ��ѡ�����������
					 ���һ�������һ����û�н�㣬ѡ��ֱ�Ӳ���
					 ������������һ�����н�㣬ѡ����뵽��ȷ��λ��
					 ����ж����޽�㣺֮ǰ�ԣ�*M��.rhead/(*M).chead���г�ʼ��������Ԫ��ֵ��ΪNULL��
					 �ж�������(*M).rhead[i] == NULL;
					*/
					
						if ((*M).rhead[irow] == NULL)
						{
							//p���ڸ��еĵ�һ����㴦
							p->right = (*M).rhead[irow];  //������ָ��Ŀո�����һ������right
							(*M).rhead[irow] = p;         //��p�ĵ�ַ������ͷָ�룬ָ���ұߵĵ�һ�����
				
						}
						else // Ѱ�����б��еĲ���λ�� 
						{
							//�Ӹ��е�������ͷ��ʼ��ֱ���ҵ�
							q = (*M).rhead[irow];
							p->right = q->right; // ����в��� 
							q->right = p;
						}

						if ((*M).chead[icol] == NULL )
						{
							// p���ڸ��еĵ�һ����㴦
							p->down = (*M).chead[icol];
							(*M).chead[icol] = p;
						}
						else // Ѱ�����б��еĲ���λ�� 
						{
							q = (*M).chead[icol];
							p->down = q->down=NULL; // ����в��� 
							q->down = p;
						}
					
					NotZeroNum++;
				}

				icol++;
				buf[irow] = (int *)realloc(buf[irow], sizeof(int) * (icol + 1));
				if (irow == 0)
				{
					(*M).chead = (OLink*)realloc((*M).chead,(icol + 1) * sizeof(OLink));
					(*M).chead[icol] = NULL;

				}

				// �����ָ�
				pch = strtok(NULL, "	");
			}

			irow++;

			(*M).rhead = (OLink*)realloc((*M).rhead, (irow + 1) * sizeof(OLink));
			(*M).rhead[irow] = NULL;
			buf = (int **)realloc(buf, sizeof(int*) * (irow + 1));
			buf[irow]= (int *)malloc(sizeof(int));


			colNum = icol;
			icol = 0;
		}
		fclose(pFile);
	}

	(*M).mu = irow;
	(*M).nu = colNum;
	(*M).tu = NotZeroNum;
	printf("\n");
	/* ������� irow��¼ʵ��������colNum��¼ʵ������*/
	for (int i = 0; i < irow; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			printf("%3d ", buf[i][j]);
		}
		printf("\n");
	}
}


/*���л������ϡ�����M*/
int OutputSMatrix(CrossList M)
{
	int i, j;
	OLink p;
	printf("%d��%d��%d������Ԫ��\n", M.mu, M.nu, M.tu);
	printf("������ѡ��(1.������� 2.�������): ");
	scanf("%d", &i);
	switch (i)
	{
	case 1://ѡ�������
		for (j = 0; j < M.mu; j++)
		{
			p = M.rhead[j];
			while (p)
			{
				printf("%d��%d��ֵΪ%d\n", (p->i), (p->j), p->e);
				p = p->right;
			}
		}
		break;
	case 2://ѡ�������
		for (j = 0; j < M.nu; j++)
		{
			p = M.chead[j];
			while (p)
			{
				printf("%d��%d��ֵΪ%d\n", (p->i), (p->j), p->e);
				p = p->down;
			}
		}
	}
	return 1;
}


/*
��ʼ������ϡ�����M��N������������Ӧ���
�����������ϡ�����Ĳ�Q = M - N
*/
int CompuSMatrix(CrossList M, CrossList N, CrossList *Q)
{
	int i, k;
	OLink p, pq, pm, pn; //��Ϊ�м���ָ��
	OLink *col;//ָ����ָ��

	if (M.mu != N.mu || M.nu != N.nu)
	{
		printf("����������ͬ���͵�,�������\n");
		exit(0);
	}
	(*Q).mu = M.mu; // ��ʼ��Q���� 
	(*Q).nu = M.nu;
	(*Q).tu = 0; 
	(*Q).rhead = (OLink*)malloc(((*Q).mu) * sizeof(OLink));//ΪQ��������ڴ�
	if (!(*Q).rhead)
		exit(0);
	(*Q).chead = (OLink*)malloc(((*Q).nu) * sizeof(OLink));
	if (!(*Q).chead)
		exit(0);
	for (k = 0; k < (*Q).mu; k++) // ��ʼ��Q����ͷָ������;��������Ϊ������ 
		(*Q).rhead[k] = NULL;
	for (k = 0; k < (*Q).nu; k++) // ��ʼ��Q����ͷָ������;��������Ϊ������ 
		(*Q).chead[k] = NULL;
	// ����ָ���е�����������
	col = (OLink*)malloc(((*Q).nu + 1) * sizeof(OLink));
	if (!col)
		exit(0);
	for (k = 0; k < (*Q).nu; k++) // ����ֵ 
		col[k] = NULL;
	for (i = 0; i < (*Q).mu; i++) // ���е�˳����� 
	{
		pm = M.rhead[i]; // pmָ�����M�ĵ�i�еĵ�1����� 
		pn = N.rhead[i]; // pnָ�����N�ĵ�i�еĵ�1����� 
		while (pm&&pn) // pm��pn������ 
		{
			if (pm->j < pn->j) // ����M��ǰ������С�ھ���N��ǰ������ 
			{
				p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
				if (!p)
					exit(0);
				(*Q).tu++; // ����Ԫ������1 
				p->i = i; // ����㸳ֵ 
				p->j = pm->j;
				p->e = pm->e;
				p->right = NULL;
				pm = pm->right; // pmָ�������� 
			}
			// ����M��ǰ�����д��ھ���N��ǰ������ 
			else if (pm->j > pn->j)
			{
				p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
				if (!p)
					exit(0);
				(*Q).tu++; // ����Ԫ������1 
				p->i = i; // ����㸳ֵ 
				p->j = pn->j;
				p->e = -pn->e;
				p->right = NULL;
				pn = pn->right; // pnָ�������� 
			}
			else if (pm->e - pn->e)
			{
				// ����M��N��ǰ�������������Ԫ��֮�Ϊ0 
				p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
				if (!p)
					exit(0);
				(*Q).tu++; // ����Ԫ������1 
				p->i = i; // ����㸳ֵ 
				p->j = pn->j;
				p->e = pm->e - pn->e;
				p->right = NULL;
				pm = pm->right; // pmָ�������� 
				pn = pn->right; // pnָ�������� 
			}
			else // ����M��N��ǰ�������������Ԫ��֮��Ϊ0 
			{
				pm = pm->right; // pmָ�������� 
				pn = pn->right; // pnָ�������� 
				continue;
			}
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 
			}
			if ((*Q).chead[p->j] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��col[p->j]ָ��p
				(*Q).chead[p->j] = col[p->j] = p;
			else // ����col[p->]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				// col[p->j]ָ����е����һ����� 
				col[p->j] = col[p->j]->down;
			}
		}
		while (pm) // ������M���е�ʣ��Ԫ�ز������Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
			if (!p)
				exit(0);
			(*Q).tu++; // ����Ԫ������1 
			p->i = i; // ����㸳ֵ 
			p->j = pm->j;
			p->e = pm->e;
			p->right = NULL;
			pm = pm->right; // pmָ�������� 
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 
			}
			if ((*Q).chead[p->j] == NULL) // pΪ���еĵ�1�����
				// p���ڸ��еı�ͷ��col[p->j]ָ��p  
				(*Q).chead[p->j] = col[p->j] = p;
			else // ����col[p->j]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				// col[p->j]ָ����е����һ����� 
				col[p->j] = col[p->j]->down;
			}
		}
		while (pn) // ������N���е�ʣ��Ԫ�ز������Q 
		{
			p = (OLink)malloc(sizeof(OLNode)); // ���ɾ���Q�Ľ�� 
			if (!p)
				exit(0);
			(*Q).tu++; // ����Ԫ������1 
			p->i = i; // ����㸳ֵ 
			p->j = pn->j;
			p->e = -pn->e;
			p->right = NULL;
			pn = pn->right; // pmָ�������� 
			if ((*Q).rhead[i] == NULL) // pΪ���еĵ�1����� 
				// p���ڸ��еı�ͷ��pqָ��p(���е����һ�����)
				(*Q).rhead[i] = pq = p;
			else // ����pq��ָ���֮�� 
			{
				pq->right = p; // ����в��� 
				pq = pq->right; // pqָ����е����һ����� 
			}
			if ((*Q).chead[p->j] == NULL) // pΪ���еĵ�1�����
				// p���ڸ��еı�ͷ��col[p->j]ָ��p 
				(*Q).chead[p->j] = col[p->j] = p;
			else // ����col[p->j]��ָ���֮�� 
			{
				col[p->j]->down = p; // ����в���
				// col[p->j]ָ����е����һ�����  
				col[p->j] = col[p->j]->down;
			}
		}
	}
	for (k = 0; k < (*Q).nu; k++)
		if (col[k]) // k���н�� 
			col[k]->down = NULL; // ��������һ������downָ��Ϊ�� 
	free(col);
	return 1;
}