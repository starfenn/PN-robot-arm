#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include"output.h"

void output1(Tree *Tr)
{
	int i;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("C:\\Users\\A237\\Desktop\\PN\\timed-PN(1)\\timed-PN\\out1.txt", "w+");
	printf("%s", "������");
	printf("\n");
	do
	{
		//fprintf(fp, "%2d\t", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		//printf("%s", " �ѵȴ�ʱ��x��");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		fprintf(fp, "%2d\t", P->new_m_come);// ��ʶ��Դ��M	
		fprintf(fp, "%2d\t", P->new_m_transition);
		if (P->old == 0)
		{
			fprintf(fp, "%2d\n", -1);
		}
		else
		{
			fprintf(fp, "%2d\n", P->old_mark); 
		}
	
		
		

		/*fprintf(fp, "m%2d�ı�ʶ�� ", P->new_m_num);
		printf("m%2d�ı�ʶ��", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " �ѵȴ�ʱ��x��");
		fprintf(fp, "%s", " �ѵȴ�ʱ��x��");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		printf("%s", " �Ѻķ�ʱ��gΪ");
		fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", " ��ʶ��Դ��M");
		printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			printf("%s", " M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", Q->new_m_num);
		}
		fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " �����ı�Ǩ");
		fprintf(fp, "%s\t", " �����ı�Ǩ");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%s", " ��������ֹ��ʶ NO");
		}
		else
		{
			printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%s", " ������ֹ��ʶ YES");
		}


		if (P->old == 0)
		{
			printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%s", " �������ظ���ʶ");
		}
		else
		{
			printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%s", " �����ظ���ʶ��");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);*/
		//}
		//fprintf(fp, "\n");
		printf("\n");
		P = P->next;
	} while (P != NULL);
	fclose(fp);
}

void output2(Tree *Tr)
{
	int i;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("C:\\Users\\A237\\Desktop\\PN\\timed-PN(1)\\timed-PN\\out2.txt", "w+");
	printf("%s", "������");
	printf("\n");
	do
	{
		////fprintf(fp, "%2d\t", P->new_m_num);
		//for (i = 0; i < (*Tr).place_num; i++)
		//{
		//	printf("%2d", P->new_m[i]);
		//	fprintf(fp, "%2d\t", P->new_m[i]);
		//}

		////printf("%s", " �ѵȴ�ʱ��x��");
		//for (i = 0; i < (*Tr).place_num; i++)
		//{
		//	printf("%2d", P->new_m_x[i]);
		//	fprintf(fp, "%2d\t", P->new_m_x[i]);
		//}
		//fprintf(fp, "%2d\t", P->new_m_come);// ��ʶ��Դ��M	
		//fprintf(fp, "%2d\t", P->new_m_transition);
		//if (P->old == 0)
		//{
		//	fprintf(fp, "%2d\n", -1);
		//}
		//else
		//{
		//	fprintf(fp, "%2d\n", P->old_mark); 
		//}

		//


		fprintf(fp, "m%2d�ı�ʶ�� ", P->new_m_num);
		printf("m%2d�ı�ʶ��", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " �ѵȴ�ʱ��x��");
		fprintf(fp, "%s", " �ѵȴ�ʱ��x��");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		printf("%s", " �Ѻķ�ʱ��gΪ");
		fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", " ��ʶ��Դ��M");
		printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			printf("%s", " M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", Q->new_m_num);
		}
		fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " �����ı�Ǩ");
		fprintf(fp, "%s\t", " �����ı�Ǩ");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%s", " ��������ֹ��ʶ NO");
		}
		else
		{
			printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%s", " ������ֹ��ʶ YES");
		}


		if (P->old == 0)
		{
			printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%s", " �������ظ���ʶ");
		}
		else
		{
			printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%s", " �����ظ���ʶ��");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		fprintf(fp, "\n");
		printf("\n");
		P = P->next;
	} while (P != NULL);
	fclose(fp);
}

void out(Tree *Tr)
{
	int i;
	int flag;
	FILE *fp;
	struct Node *P, *Q;
	P = (*Tr).head_Node;
	fp = fopen("C:\\Users\\A237\\Desktop\\PN\\timed-PN(1)\\timed-PN\\backout1.txt", "w+");
	printf("%s", "������");
	printf("\n");
	do
	{
		fprintf(fp, "m%2d�ı�ʶ��", P->new_m_num);
		printf("m%2d�ı�ʶ��", P->new_m_num);
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m[i]);
			fprintf(fp, "%2d\t", P->new_m[i]);
		}

		printf("%s", " �ѵȴ�ʱ��x��");
		fprintf(fp, "%s", " �ѵȴ�ʱ��x��");
		for (i = 0; i < (*Tr).place_num; i++)
		{
			printf("%2d", P->new_m_x[i]);
			fprintf(fp, "%2d\t", P->new_m_x[i]);
		}
		//for(i=0;i<place_num;i++)
		//{
		//	printf("%2d",P->new_m_flag[i]);
		//	fprintf(fp,"%2d\t",P->new_m_flag[i]);
		//}
		printf("%s", " �Ѻķ�ʱ��gΪ");
		fprintf(fp, "%s", " �Ѻķ�ʱ��gΪ");
		printf("%2d", P->new_m_g);
		fprintf(fp, "%2d\t", P->new_m_g);
		printf("%s", " ���ƺķ�ʱ��hΪ");
		printf("%2d", P->new_m_h);
		printf("%s", " ������С�ķ�ʱ��hΪ");
		printf("%2d", P->new_m_h_min);
		printf("%s", " ��ʶ��Դ��M");
		fprintf(fp, "%s", " ��ʶ��Դ��M");
		printf("%2d", P->new_m_come);
		Q = P->source;
		if (Q == NULL)
		{
			printf("%s", " M");
			printf("%2d", 0);
		}
		else
		{
			printf("%s", " M");
			printf("%2d", Q->new_m_num);
		}
		fprintf(fp, "%2d\t", P->new_m_come);
		printf("%s", " �����ı�Ǩ");
		fprintf(fp, "%s\t", " �����ı�Ǩ");
		printf("%2d", P->new_m_transition);
		fprintf(fp, "%2d\t", P->new_m_transition);

		if (P->finish == 0)
		{
			printf("%s", " ��������ֹ��ʶ NO");
			fprintf(fp, "%s", " ��������ֹ��ʶ NO");
		}
		else
		{
			printf("%s", " ������ֹ��ʶ YES");
			fprintf(fp, "%s", " ������ֹ��ʶ YES");
		}


		if (P->old == 0)
		{
			printf("%s", " �������ظ���ʶ");
			fprintf(fp, "%s", " �������ظ���ʶ");
		}
		else
		{
			printf("%s", " �����ظ���ʶ��");
			fprintf(fp, "%s", " �����ظ���ʶ��");
			printf("%2d", P->old_mark);
			fprintf(fp, "%2d\t", P->old_mark);
		}
		fprintf(fp, "\n");
		printf("\n");
		P = P->next_open;
	} while (P != NULL);
	fclose(fp);
}
