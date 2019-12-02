
#include "Completecrosslinkedlist .h"
#include "Is_enabled.h"

/*
 �ж��ڵ�ǰ��ʶ�£���ǨTransition�Ƿ���Լ���
 CrossList SMatrix_C_pre :  ǰ�ù������� 
 int current_m[] :  ��ʶ
 int Transition : ��Ǩ
 Return ��int  0��ʾ�ڱ�ʶcurrent_m[]�±�ǨTransition���ܼ�����1�����
*/
bool Is_enabled(int current_m[], int Transition)
{
	OLink p;
	p = C_pre.chead[Transition]; 
	while (p)
	{
		if (current_m[p->i] > p->e || current_m[p->i] == p->e)
		{
			p = p->down;
		}
		else
		{
			return  0;			
		}
	}
	return 1;

}