#pragma once
#include"pch.h"

struct InPutVal
{
	int OutDiffer[4];
	int InDiffer[6];
	int Boxname=0;
};
		
//ʮ����ת��Ϊ��������������
void DecToBit(int Dec, int Bitarry[],int bits);	

//������ת��Ϊʮ����
void BitToDec(int Bitarry[], int & Dec, int bits);

//����6bit��S���ӵı�ţ����4bit
void _Box(int input[6], int output[4],int Boxnum);

//input�����֣�out��������Ժ�����SBox�����������
void Auftrag1_main(int input[6]);

//��ʼ������б�INPUT:SBox������
void InitDiffGrap(int input[6], int DiffGrap[16][64]);

//����һ�β�ַ�����INPUT:����Ժ���Կ
void SearchKey(int input_1[6], int input_2[6], int Key[6], int Cout[64]);

//ͨ����ַ��������Կ
void Auftrag5_main(int Key[6]);