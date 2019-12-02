#include <stdlib.h> 
#include<stdio.h>
#include "tree_node.h"
#include "AddNewNode.h"

/*
�ж��Ƿ�Ϊ��ֹ��չ���
Tree *Tr :  ��
Return void
*/
//extern int place_num;

void finish_node(Tree *Tr)
{
	int have_enabled = 0;
	int Transition, is_enabled;
	for (Transition = 0; Transition < (*Tr).transition_num; Transition++)
	{
		
		is_enabled = Is_enabled((*Tr).current_node->new_m, Transition);
		if (is_enabled == 1)
		{
			have_enabled = 1;
		}
	}
	if (have_enabled == 0)
	{
		(*Tr).current_node->finish = 1;
		(*Tr).current_node->finish_node = NULL;
		if ((*Tr).finish_head_Node == NULL)
		{
			(*Tr).finish_head_Node = (*Tr).current_node;
			(*Tr).finish_node_end = (*Tr).current_node;
		}
		else
		{
			(*Tr).finish_node_end->finish_node = (*Tr).current_node;
			(*Tr).finish_node_end = (*Tr).current_node;
		}
	}
	else
	{
		(*Tr).current_node->finish = 0;
		(*Tr).current_node->finish_node = NULL;
	}
}

/*
���½�����ӵ�open����ĩβ
Tree *Tr :  ��
int produce_new :  ���ĵ�ǰ���Ϊ��
Return void
*/
void AddNewNode(Tree *Tr,int produce_new)
{
	if (produce_new == 1)//���±�ʶ������Ҫ����չ��һ���½ڵ� 
	{
		(*Tr).current_node->old = 0;
		(*Tr).current_node->old_mark = 0;
		finish_node(Tr);
		(*Tr).open_end->next_open = (*Tr).current_node;
		(*Tr).open_end = (*Tr).current_node;
		(*Tr).current_node->same = NULL;
		(*Tr).current_node->same_end = NULL;
	}
}
