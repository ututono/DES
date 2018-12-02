#include "pch.h"
#include"Auftrag2.h"


int BeforeChangeC[64];
int AfterChandeC[64];
extern void CharToBit(const char input[], int output[], int bits);
extern void BitToChar(const int intput[], char output[], int bits);
extern void  DES_Efun(char input[8], char key_in[8], int output[64]);
extern void  DES_Dfun(int input[64], char key_in[8], char output[8]);

//生成一个不重复的随机数数组
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
	int Repeat = 50;				//重复改变明文次数
	int Count = 0;					//密文改变的位数
	DES_Efun(stext, key, BeforeChangeC);
	int changeplazt = 0;			//改变位置
	do
	{
		CharToBit(stext, stextBits, 8);
		NieWiederRand(RandArry, 64);
		for (int i = 0; i < changebits; i++)
		{
			changeplazt = RandArry[i];
			stextBits[changeplazt] = (stextBits[changeplazt] + 1) % 2;	//	将改变位数上的二进制反转
		}
		BitToChar(stextBits, changestext, 8);						//将改变的明文转化成CHAR
		DES_Efun(changestext, key, AfterChandeC);			//计算改变明文输出的密文
		Count = Compare(BeforeChangeC, AfterChandeC, 64)+ Count;
	} while (--Repeat);	
	printf("重复五十次，密文平均改变位数：%6.2f\n", (float)Count/50);
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
	printf("密钥改变%d位，重复五十次，密文平均改变位数：%6.2f\n",changebits, (float)Count / 50);
	}
