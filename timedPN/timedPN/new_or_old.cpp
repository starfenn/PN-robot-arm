#include <stdlib.h> 
#include<stdio.h>
#include <string.h>
#include "tree_node.h"
#include "Completecrosslinkedlist .h"
#include "new_or_old.h"

/*
�ж�����ǰ��㣨formerָ��Ľ�㣩���»��Ǿ�
Tree *Tr :  ��
Return void
*/ //&& (*Tr).current_node->new_m_x[i] == P->new_m_x[i]    (*Tr).current_node->new_m_g == P->new_m_g 
bool new_or_old(Tree *Tr)//�ж����µĻ��Ǿɵ� 
{
	int i, Flag;
	int same = 1,a=1;
	struct Node *P, *S;
	P = (* Tr).head_Node;
	do
	{
		for (i = 0; i < (*Tr).place_num; i++)
		{
			if ((*Tr).current_node->new_m[i] == P->new_m[i])//���ɵ��±�ʶ������ĵ�һ�����ı�ʶÿһλ�ж��Ƿ���ͬ����ͬΪ�棩 
			{
				same = 1;
			}
			else
			{
				same = 0;
				break;//��ʶ���i�в�ͬ���˳�ѭ���ж���һ�� 
			}
		}
		if (same == 1)
		{
			for (i = 0; i < 27; i++)
			{
				if ((*Tr).current_node->new_m_x[i] == P->new_m_x[i] || (*Tr).current_node->new_m_x[i] - P->new_m_x[i] >= 10)
				{
					a = 1;
				}
				else
				{
					a = 0;
					break;
				}
			}
		}
		if (same == 1 &&((*Tr).current_node->new_m_g - P->new_m_g >=10 || (*Tr).current_node->new_m_g == P->new_m_g) &&a==1)
		{
			Flag = 0;
			(*Tr).current_node->old = 1;
			(*Tr).current_node->same = NULL;
			(*Tr).current_node->same_end = NULL;
			(*Tr).current_node->old_mark = P->new_m_num;
			(*Tr).current_node->finish = 0;
			if (P->same == NULL)
			{
				P->same = (*Tr).current_node;
				P->same_end = (*Tr).current_node;
			}
			else
			{
				S = P->same_end;
				S->same = (*Tr).current_node;
				P->same_end = (*Tr).current_node;
			}
			break;//��ͬ�����˳��жϣ��������ӱ�־ 
		}
		else
		{
			Flag = 1;
		}
		P = P->next_open;
	} while (P != NULL);

	if (Flag == 1)
	{
		return 1;
	}
	else
	{
		(*Tr).current_node->next_open = NULL;
		return 0;
	}
}

