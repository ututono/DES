#include "pch.h"
#include"Auftrag1.h"

InPutVal *S_Input;

struct inputdui
{
	int input[6];
};

void DecToBit(int input, int Bitarry[],int bits)						
{
	int Dexnum = input;
	int i = bits-1;
	int temp = 0;
	while (i+1)
	{
		Bitarry[i--] = Dexnum % 2;
		Dexnum = Dexnum / 2;
	}
}

void BitToDec(int Bitarry[], int & Dec,int bits)
{
	int tmp = pow(2, bits - 1);
	Dec = 0;
	if (Bitarry[bits-1] == 1) Dec = 1;
	for (int i = 0; i <bits-1; i++)
	{
		if (Bitarry[i] == 1)
			Dec = Dec+tmp;
		tmp = tmp / 2;
	}
}

void _Box(int input[6], int output[4],int Boxnum)
{
	extern int S_Box[8][4][16];
	int x, y, tmp;
	x = 2 * input[0] + input[5];
	y = 2 * 2 * 2 * input[1] + 2 * 2 * input[2] + 2 * input[3] +  input[4];
	tmp = S_Box[Boxnum][x][y];
	DecToBit(tmp, output,4);
}

void Auftrag1_main(int input[6])
{
	int input_1[6], input_2[6];
	int out_1[4], out_2[4], outDiff[4],outDiff_2[4];
	int Flag = 0;
	printf("————————————————————————————————————————————————————\n");
	for (int boxname = 0; boxname < 8; boxname++)
	{
		printf("S%d盒的所有输入对和输出差分：\n\n", boxname+1);
		for (int i = 0; i < 16; i++)
		{
			DecToBit(i, outDiff_2, 4);
			int Count = 0;
			for (int z = 0; z < 4; z++)
			{
				printf("%d", outDiff_2[z]);			//打印当前的输出差分
			}
			printf("\t");
			for (int j = 0; j < 64; j++)
			{
				DecToBit(j, input_1, 6);			//将十进制转化成二进制按位存储在整型数组中
				for (int k = 0; k < 6; k++)
				{
					input_2[k] = input_1[k] ^ input[k];
				}
				_Box(input_1, out_1, boxname);			//获取输出比特串
				_Box(input_2, out_2, boxname);
				for (int k = 0; k < 4; k++)
				{
					outDiff[k] = out_1[k] ^ out_2[k];
				}
				Flag = 1;
				for (int k = 0; k < 4; k++)
				{
					if (outDiff[k] != outDiff_2[k])
					{
						Flag = 0;
						break;
					}
				}
				if (Flag == 1)				//Flag=1说明计算的输出差分和当前输出差分一致
				{
					Count++;
					for (int m = 0; m < 6; m++)
					{
						printf("%d", input_1[m]);
					}
					printf(",");
				}
			}
			if (Count == 0) printf("无输入");
			else printf("\t输入数量为:	%d", Count);
			printf("\n");
		}
		printf("————————————————————————————————————————————————————\n");
	}
}

//INPUT:输入差分
void InitDiffGrap(int input[6],int DiffGrap[16][64])
{
	int input_1[6], input_2[6];
	int out_1[4], out_2[4], outDiff[4], outDiff_2[4];
	int Flag = 0;
	const int boxname = 0;
	//int DiffGrap[16][64];

	//差分列表的初始化
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			DiffGrap[i][j] = -1;
		}
	}
		
	for (int i = 0; i < 16; i++)
	{
		DecToBit(i, outDiff_2, 4);
		int Count = 0;

		for (int j = 0; j < 64; j++)
		{
			DecToBit(j, input_1, 6);			//将 <j> 十进制转化成二进制按位存储在<input_1>中
			for (int k = 0; k < 6; k++)
			{
				input_2[k] = input_1[k] ^ input[k];			//<input_2>中存储的是的是另一个输入
			}
			_Box(input_1, out_1, boxname);			//获取<j>的输出数组<out_1>
			_Box(input_2, out_2, boxname);
			for (int k = 0; k < 4; k++)
			{
				outDiff[k] = out_1[k] ^ out_2[k];
			}
			Flag = 1;
			for (int k = 0; k < 4; k++)
			{
				if (outDiff[k] != outDiff_2[k])
				{
					Flag = 0;
					break;
				}
			}
			if (Flag == 1)				//Flag=1说明计算的输出差分和当前输出差分一致
			{
				Count++;
				int Input1_Dex = 0;
				BitToDec(input_1, Input1_Dex,6);
				DiffGrap[i][Count] = Input1_Dex;
			}
		}
	}
}

//INPUT:输入对和密钥
void SearchKey(int input_1[6],int input_2[6],int Key[6],int Cout[64])
{
	int S_input_1[6] = { 0 };
	int S_input_2[6] = { 0 };
	int InputDiff[6] = { 0 };
	int out_1[4], out_2[4], outDiff[4], outDiff_2[4];
	const int boxname = 0;
	int DiffGrap[16][64];
	

	for (int k = 0; k < 6; k++)
	{
		S_input_1[k] = input_1[k] ^ Key[k];
		S_input_2[k] = input_2[k] ^ Key[k];
	}
	for (int k = 0; k < 6; k++)								//输入差分
	{
		InputDiff[k] = S_input_1[k] ^ S_input_2[k];
	}
	InitDiffGrap(InputDiff, DiffGrap);

	_Box(S_input_1, out_1, boxname);			
	_Box(S_input_2, out_2, boxname);

	for (int k = 0; k < 4; k++)								//输出差分
	{
		outDiff[k] = out_1[k] ^ out_2[k];
	}

	int outDiff_Dex = 0;
	BitToDec(outDiff, outDiff_Dex,4);

	for (int j = 0; j < 64; j++)			//找密钥
	{
		if (DiffGrap[outDiff_Dex][j] > 0)
		{
			int temp[6],temp1[6],temp1_Dex=0;
			DecToBit(DiffGrap[outDiff_Dex][j], temp, 6);
			for (int k = 0; k < 6; k++)								
			{
				temp1[k] = temp[k] ^input_1[k];
			}
			BitToDec(temp1, temp1_Dex,6);
			Cout[temp1_Dex]++;
		}
	}

	//for (int i = 0; i < 64; i++)
	//{
	//	if (Cout[i] > 0) printf("%4d:%d, ", i, Cout[i]);
	//}
}

void Auftrag5_main(int Key[6])
{
	const int times = 3;
	int Cout[64] = { 0 };
	int result[6];
	for (int i = 0; i < times; i++)
	{
		int input1 = rand() % 64;
		int input2 = rand() % 64;
		int input1B[6];
		int input2B[6];
		DecToBit(input1, input1B, 6);
		DecToBit(input2, input2B, 6);
		SearchKey(input1B, input2B, Key, Cout);

		int print[6];
		printf("第%d轮差分\t", i);
		for (int m = 0; m < 64; m++)
		{
			if (Cout[m] > 0)
			{
				DecToBit(m, print, 6);
				for (int k = 0; k < 6; k++)
				{
					printf("%d", print[k]);
				}
				printf("*%3d*,  ", Cout[m]);
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 64; i++)
	{
		if (Cout[i] == times)
		{
			DecToBit(i, result, 6);
			printf("密钥是:");
			for (int j = 0; j < 6; j++)
			{
				printf("%d", result[j]);
			}
			printf("\n");
		}
	}
}
