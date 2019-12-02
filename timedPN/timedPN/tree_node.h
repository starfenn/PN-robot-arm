#pragma once
#define Len_node         sizeof(struct Node)


typedef struct Node
{
	int new_m_num;//�±�ʶ���±�
	int *new_m;//�¾����ʶ
	int *new_m_x; // ��ʱ�̿������п��Ѿ��ȴ�ʱ��
	int new_m_g; //�Ѻķѵ�ʱ�����
	int new_m_h; //����ֵ
	int new_m_h_min; // ����ֵ��Сֵ
	int new_m_come;//�±�ʶ�ı�ʶ��Դ
	struct Node *source; //�±�ʶ����Դ�ڵ�   
	int new_m_transition;//�±�ʶ�ı�Ǩ��Դ
	struct Node *next_open;//��һ��Ҫ��չ�ı�ʶ
	struct Node *next; //��һ������ַ
	int old; //�ɵı�ʶ
	struct Node *same; //�״���ͬ�ı�ʶ 
	struct Node *same_end; //ĩβ��ͬ�ı�ʶ 
	int old_mark;//�ɵı�ʶ���±�
	int finish;  //��ֹ��չ��� 
	struct Node *finish_node; // �״�������ֹ���
} *Nodelink;


typedef struct
{
	Node *head_Node; //ָ�����ĵ�һ�����
	Node *current_node;  //��ǰ���
	Node *last_node;  //��ǰ������һ�����
	Node *finish_head_Node; //������ֹ���
	Node *finish_node_end; // ĩβ������ֹ���
	Node *open_end;  //��չ��β���   
	Node *source_node; //������Դ���
	int  place_num;  //��������
	int  transition_num; //��Ǩ����
	int  node_num; // ���Ľ�����
}Tree;   //Tree�ṹ��
