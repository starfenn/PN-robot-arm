#pragma once

typedef int ElemType;
typedef struct OLNode
{
	int i, j;    // �÷���Ԫ���к����±� 
	ElemType e;    // ����Ԫ��ֵ 
	struct OLNode *right, *down; // �÷���Ԫ�����б���б�ĺ������ 
}OLNode, *OLink;


typedef struct// �к�������ͷָ��������ַ,��CreatSMatrix_OL()����
{
	OLink *rhead, *chead;
	int mu, nu, tu;        // ϡ�����������������ͷ���Ԫ���� 
}CrossList;


int InitSMatrix(CrossList *M);    // ��ʼ��M(CrossList���͵ı��������ʼ��,���򴴽������ƾ��󽫳���) 
int DestroySMatrix(CrossList *M);    // ����ϡ�����M
void CreateSMatrix(CrossList *M, const char *path);     // ����ʮ������洢��ʾ
int OutputSMatrix(CrossList M);  // ���л������ϡ�����M
int CompuSMatrix(CrossList M, CrossList N, CrossList *Q); //  ��ϡ�����Ĳ�Q=M-N 
