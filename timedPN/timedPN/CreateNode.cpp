#include<stdio.h>
#include <stdlib.h>
#include "tree_node.h"
#include "Completecrosslinkedlist .h"
#include "CreateNode.h"

/*
��current_m[]�£���ǨTransition�����������µĽ��
Tree *Tr :  ��
int Transition :  ������Ǩ
int new_m[] : ��ʶ
Return void
*/

void CreateNode(Tree *Tr, int Transition, int current_m[],int place_num,int Delay[],int new_m_x[], int new_m_g)
{
	int T_num, i,ans,step=0,g;
	int *m = (int *)malloc(sizeof(int) * place_num);
	int *x = (int *)malloc(sizeof(int) * place_num);
	OLink P,Q;
	P = C.chead[Transition];
	Q = C_pre.chead[Transition];
	for (i = 0; i < (*Tr).place_num; i++)
	{
		x[i] = new_m_x[i];
		m[i] = current_m[i];
	}
	
	while (P != NULL)//���±�ʶ
	{
		/*printf("m[%d]", P->i);*/
		m[P->i] = m[P->i] + (P->e);
		/*printf("%d", m[P->i]);*/
		P = P->down;
	}
	//printf("\n");
	while (Q != NULL) //����step 
	{
		ans = Delay[Q->i] * (Q->e) - x[Q->i];                //���ʱ��=��ʱʱ��*ǰ��ֵ-�ѵȴ�ʱ��      
		if (ans > step)                //��0���Ƚ�
			step = ans;
		Q = Q->down;
	}
	printf("%2d", step);//step��ʾ��ǰ��ʶ����һ��ʶ�����ʱ��
	g = new_m_g + step;                                      //�ѺķѴ���+��Ĵ���
	for (i = 0; i < (*Tr).place_num; i++) //���½�㴦��x     �����ѵȴ�ʱ��
	{
		if (Delay[i] == 0)
		{
			x[i] = 0;
		}
		else
		{
			if (m[i] == 0)
			{
				x[i] = 0;
			}
			else
			{
				if (current_m[i] == 0)
				{
					x[i] = 0;
				}
				else
				{
					x[i] = x[i] + step;
				}
			}
		}
	}

	T_num = Transition + 1;
	(*Tr).node_num++;//����Ľ������һ 
	(*Tr).current_node = (Nodelink)malloc(Len_node);//�����µĽ�㣬���ַ������ǰ���
	(*Tr).last_node->next = (*Tr).current_node;//����һ������nextָ���½��Ľ�� 
	(*Tr).last_node = (*Tr).current_node;//ʹlatterҲָ���½��Ľ�� 	
	(*Tr).current_node->new_m = (int *)malloc(sizeof(int) * place_num);
	(*Tr).current_node->new_m_x = (int *)malloc(sizeof(int) * place_num);
	for (i = 0; i < (*Tr).place_num; i++)//���½��Ľ�㸳ֵ 
	{
		(*Tr).current_node->new_m[i] = m[i]; //�������±�ʶ�ŵ�������� 
		(*Tr).current_node->new_m_x[i] = x[i];
	}
	(*Tr).current_node->new_m_g = g;
	(*Tr).current_node->new_m_h_min = 100;
	(*Tr).current_node->new_m_come = ((*Tr).source_node)->new_m_num;//��ʶ����Դ�±�ŵ�������� 
	(*Tr).current_node->source = (*Tr).source_node;
	(*Tr).current_node->new_m_transition = T_num;//��ʶ�����ı�Ǩ���±�ŵ�������� 
	(*Tr).current_node->new_m_num = (*Tr).node_num;
	(*Tr).current_node->next = NULL;
	(*Tr).current_node->next_open = NULL;
}

