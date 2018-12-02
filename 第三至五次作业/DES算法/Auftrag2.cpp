#include "pch.h"
#include"Auftrag2.h"


int BeforeChangeC[64];
int AfterChandeC[64];
extern void CharToBit(const char input[], int output[], int bits);
extern void BitToChar(const int intput[], char output[], int bits);
extern void  DES_Efun(char input[8], char key_in[8], int output[64]);
extern void  DES_Dfun(int input[64], char key_in[8], char output[8]);

//����һ�����ظ������������
void NieWiederRand(int IntArry[],int length)
{
	for (int i = 0; i < length; i++)
	{
		IntArry[i] = i ;
	}
	int t = 0;
	for (int i = length-1; i >0; i--)
	{
		int w = rand() % i;
		t = IntArry[i];
		IntArry[i] = IntArry[w];
		IntArry[w] = t;
	}
}


int Compare(int VorC[],int DannC[],int length)
{
	int Count = 0;
	for (int i = 0; i < length; i++)
	{
		if (VorC[i]!=DannC[i])
		{
			Count++;
		}
	}
	return Count;
}


void Auftrag2_main(char stext[], char key[], int changebits)
{
	char changestext[8];
	int RandArry[64];
	int stextBits[64];
	int keyBits[64];
	int Repeat = 50;				//�ظ��ı����Ĵ���
	int Count = 0;					//���ĸı��λ��
	DES_Efun(stext, key, BeforeChangeC);
	int changeplazt = 0;			//�ı�λ��
	do
	{
		CharToBit(stext, stextBits, 8);
		NieWiederRand(RandArry, 64);
		for (int i = 0; i < changebits; i++)
		{
			changeplazt = RandArry[i];
			stextBits[changeplazt] = (stextBits[changeplazt] + 1) % 2;	//	���ı�λ���ϵĶ����Ʒ�ת
		}
		BitToChar(stextBits, changestext, 8);						//���ı������ת����CHAR
		DES_Efun(changestext, key, AfterChandeC);			//����ı��������������
		Count = Compare(BeforeChangeC, AfterChandeC, 64)+ Count;
	} while (--Repeat);	
	printf("�ظ���ʮ�Σ�����ƽ���ı�λ����%6.2f\n", (float)Count/50);
}

void Auftrag3_main(char stext[], char key[], int changebits)
{
	char changekey[8];
	int RandArry[64];
	int keyBits[64];
	int Count = 0, times = 50;
	do
	{
		NieWiederRand(RandArry, 64);
		DES_Efun(stext, key, BeforeChangeC);
		CharToBit(key, keyBits, 8);
		for (int i = 0; i < changebits; i++)
		{
			keyBits[RandArry[i]] = (keyBits[RandArry[i]] + 1) % 2;
		}
		BitToChar(keyBits, changekey, 8);
		DES_Efun(stext, changekey, AfterChandeC);
		Count =Compare(BeforeChangeC, AfterChandeC, 64) + Count;
	} while (--times);
	printf("��Կ�ı�%dλ���ظ���ʮ�Σ�����ƽ���ı�λ����%6.2f\n",changebits, (float)Count / 50);
	}
