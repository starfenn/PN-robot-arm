//#include"back_tree.h"
#include "tree_node.h"
#include "output.h"
#include <stdlib.h> 
#include<stdio.h>

//void back_output(Node *node, Tree *Tr)
//{
//	printf("m%2d�ı�ʶ��", node->new_m_num);
//	for (int i = 0; i < (*Tr).place_num; i++)
//	{
//		printf("%2d", node->new_m[i]);
//	}
//	printf("%s", " �ѵȴ�ʱ��x��");
//	for (int i = 0; i < (*Tr).place_num; i++)
//	{
//		printf("%2d", node->new_m_x[i]);
//	}
//	printf("%s", " �Ѻķ�ʱ��gΪ");
//	printf("%2d", node->new_m_g);
//	printf("%s", " ���ƺķ�ʱ��hΪ");
//	printf("%2d", node->new_m_h);
//	printf("%s", " ������С�ķ�ʱ��hΪ");
//	printf("%2d", node->new_m_h_min);
//	printf("%s", " ��ʶ��Դ��M");
//	printf("%2d", node->new_m_come);
//	printf("%s", " �����ı�Ǩ");
//	printf("%2d", node->new_m_transition);
//	if (node->finish == 0)
//	{
//		printf("%s", " ��������ֹ��ʶ NO");
//	}
//	else
//	{
//		printf("%s", " ������ֹ��ʶ YES");
//	}
//	if (node->old == 0)
//	{
//		printf("%s", " �������ظ���ʶ");
//	}
//	else
//	{
//		printf("%s", " �����ظ���ʶ��");
//		printf("%2d", node->old_mark);
//	}
//	printf("\n");
//}

void node_back_open(Node *node, Tree *Tr, int time_cost)
{
	if (node != NULL)
	{
		node->new_m_h = time_cost - node->new_m_g;
		if (node->new_m_h < node->new_m_h_min)
		{
			node->new_m_h_min = node->new_m_h;
		}
		//back_output(node, Tr);
		node_back_open(node->source, Tr, time_cost);
		struct Node *same_node, *source_node;
		same_node = node->same;
		while (same_node != NULL)
		{
			source_node = same_node->source;
			node_back_open(source_node, Tr, time_cost);
			same_node = same_node->same;
		}
	}
}


void back_tree(Tree *Tr)
{
	struct Node *finish_node;
	//struct Node *head_backtree;
	finish_node = Tr->finish_head_Node;
	int num = 1;
	while (finish_node != NULL)
	{
		printf("\n");
		printf("��%2d�÷��������", num);
		printf("\n");
		node_back_open(finish_node, Tr, finish_node->new_m_g);
		printf("��%2d�÷������������", num);
		printf("\n");
		num = num + 1;
		finish_node = finish_node->finish_node;
	}
}


