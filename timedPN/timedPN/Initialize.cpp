#include "tree_node.h"
#include <stdio.h>
#include <stdlib.h>
#include "Initialize.h"



/*
��ʼ����
Tree *Tr :  ��
int place_num :  ��������
int trainsition_num :  ��Ǩ����
Return void
*/
void InitTree(Tree *Tr, int place_num, int trainsition_num)
{
	(*Tr).head_Node = (*Tr).finish_head_Node = NULL;
	(*Tr).current_node = (*Tr).last_node = (*Tr).open_end = (*Tr).source_node =(*Tr).finish_node_end  = NULL;
	(*Tr).node_num = 0;
	(*Tr).place_num = place_num;
	(*Tr).transition_num = trainsition_num;
}




/*
�������ĵ�һ�����
Tree *Tr :  ��
int M0[] :  ��ʼ��ʶ
Return void
*/
void InitNode(Tree *Tr, int M0[],int  place_num)
{
	//������̬����ĵ�һ����� 
	(*Tr).head_Node = (*Tr).current_node = (*Tr).last_node = (Nodelink)malloc(Len_node);  //ΪNodelink�ṹ��ָ������ֽ�ΪLen_node(�ṹ��Node)�Ķ�̬�ڴ�
	(*Tr).node_num = 0;

	//��ʼ����һ���������� 
	(*Tr).current_node->new_m= (int *)malloc(sizeof(int) * place_num);

	for (int i = 0; i < (*Tr).place_num; i++)//��ʼ����һ�����ľ����ʶ 
	{
		(*Tr).current_node->new_m[i] = M0[i]; 
	}

	(*Tr).current_node->new_m_x = (int *)malloc(sizeof(int) * place_num);

	for (int i = 0; i < (*Tr).place_num; i++)//��ʼ����һ�����ľ����ʶ�ĵȴ�ʱ�� 
	{
		(*Tr).current_node->new_m_x[i] = 0;
	}

	(*Tr).current_node->new_m_num = 0;      //��һ�����ı�ʶ�±���0
	(*Tr).current_node->new_m_g = 0;
	(*Tr).current_node->new_m_h_min = 100;
	(*Tr).current_node->new_m_come = 0;     //�ޱ�ʶ��Դ
	(*Tr).current_node->source = NULL;      //����Դ���
	(*Tr).current_node->new_m_transition = 0;//�ޱ�Ǩ��Դ

	(*Tr).current_node->next = NULL;        //����һ����㸳Ϊ��
	(*Tr).current_node->next_open = NULL;
	(*Tr).current_node->old = 0;
	(*Tr).current_node->same = NULL;
	(*Tr).current_node->same_end = NULL;
	(*Tr).current_node->old_mark = 0;
	(*Tr).current_node->finish = 0;
	(*Tr).current_node->finish_node = NULL;
	(*Tr).open_end = (*Tr).current_node;   //��ǰ������Ҳ����չβ���
}