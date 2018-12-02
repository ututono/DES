#pragma once
#include"pch.h"

struct InPutVal
{
	int OutDiffer[4];
	int InDiffer[6];
	int Boxname=0;
};
		
//十进制转换为二进制整型数组
void DecToBit(int Dec, int Bitarry[],int bits);	

//二进制转换为十进制
void BitToDec(int Bitarry[], int & Dec, int bits);

//输入6bit和S盒子的编号，输出4bit
void _Box(int input[6], int output[4],int Boxnum);

//input输入差分，out所有输入对和所有SBox的输出差分情况
void Auftrag1_main(int input[6]);

//初始化差分列表，INPUT:SBox输入差分
void InitDiffGrap(int input[6], int DiffGrap[16][64]);

//进行一次差分分析，INPUT:输入对和密钥
void SearchKey(int input_1[6], int input_2[6], int Key[6], int Cout[64]);

//通过差分分析获得密钥
void Auftrag5_main(int Key[6]);