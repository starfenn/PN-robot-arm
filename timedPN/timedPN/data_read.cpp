#include<stdio.h>
#include "data_read.h"

/*
��ȡ��ʼ��ʶM0
int place_num :  ��������
int M0[] :  ��ʼ��ʶ
Return��void 
*/
void data_read(int place_num, int M0[],int Delay[])
{
	int i;
	FILE *fp;
	fp = fopen(M0_path, "r"); //��ȡ��ʼ��ʶ 
	if (fp == NULL)
	{
		printf("cannot open file\n");
	}
	for (i = 0; i < place_num; i++)
	{
		fscanf(fp, "%d", &M0[i]);
	}
	fclose(fp);

	printf("��ʼ��ʶ��\n"); 
	for (i = 0; i < place_num; i++)
	{
		printf("%3d", M0[i]);
	}
	printf("\n");

	fp = fopen(Delay_path, "r"); //��ȡ�����ϸ�ʱʱ�� 
	if (fp == NULL)
	{
		printf("cannot open file\n");
	}
	for (i = 0; i < place_num; i++)
	{
		fscanf(fp, "%d", &Delay[i]);
	}
	fclose(fp);

	printf("������ʱʱ�䣺\n"); //�����ʱʱ�� 
	for (i = 0; i < place_num; i++)
	{
		printf("%3d", Delay[i]);
	}
	printf("\n");

}