// Algorithm1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define SIZEBITS_PRIME 4 //素数的位数 
//int main()
//{
//	char test[] = "啊";
//	
//	
//	
//	
//
//	getchar();
//	return 0;
//}

int CNTOUnicode(char *input, wchar_t *output)
{
	int len = strlen(input);
		//wchar_t *out = (wchar_t *) malloc(len*sizeof(wchar_t));
	len = MultiByteToWideChar(CP_ACP, 0, input, -1, output, MAX_PATH);
		return 1;
}


int main()
{
	extern bool Pass;
	srand((unsigned)time(NULL)*20);
	
	int length = 100;
	long unsigned int *arry;
	unsigned long int Prime = 0,times=1,Prime2=0;		
	unsigned long long e = 0,n=0;
	long long  d = 0, y = 0;
	clock_t tstart, tend;

	tstart = clock();
	while (!Prime)
	{
		Prime = F(SIZEBITS_PRIME, 50);			//Prime为所找到的素数
		if (times % 1000000 == 0)
			printf("百万次F计算标记点\n");
		times++;
	}
	printf("%lu为找到的可能素数\n", Prime);
	tend = clock();
	printf("the Time is: %f Second\n", (double)(tend - tstart) / CLOCKS_PER_SEC);
	
	tstart = clock();
	if (IsPrime(Prime)) printf("经检验%lu确实是素数\n", Prime);
	else printf("其实%lu是合数达\n",Prime);
	tend = clock();
	printf("the Time is: %f Second\n", (double)(tend - tstart) / CLOCKS_PER_SEC);


	while (!Prime2 || (Prime==Prime2))
	{
		Prime2 = F(SIZEBITS_PRIME, 50);			//Prime为所找到的素数
		if (times % 1000000 == 0)
			printf("百万次F计算标记点\n");
		times++;
	}

	unsigned long long Eul = (Prime - 1)*(Prime2 - 1);

		while (!e)
		{
			e = F(SIZEBITS_PRIME - 1, 50);			//Prime为所找到的素数
			if (times % 1000000 == 0)
				printf("百万次F计算标记点\n");
			times++;
		}

	ExtGCD(e, Eul, d, y);
	n = Prime * Prime2;
	while (d<0)
	{
		d += Eul;
	}

	char MInput[500];
	wchar_t  MUinput[500];
	wchar_t wc;
	printf("请输入明文");
	scanf_s("%s", MInput);

	unsigned long long M = 65530;
	unsigned long long C = ModExp(M, e, n);
	printf("加密结果:%lu\n", C);


	printf("解密结果:%lu\n", ModExp(C, d, n));
	
	printf("已经结束;\n");
	getchar();
	return 0;

		//测试miller算法
		//int i =3251;
		//arry = (long unsigned int *)calloc(i, sizeof(long unsigned int));
		//randarry(arry, i);
		//Pass = 0;
		//for (int j = 0; j < 8; j++)
		//{
		//	Miller(i, arry[j]);
		//	if (i < 4)
		//	{
		//		Pass = 1;
		//	}
		//	if (Pass == 0)
		//	{
		//		printf("%d该数是合数\n", i);
		//		break;
		//	}
		//}
		//if(Pass==1) printf("%d可能是素数\n", i);
		//free(arry);

}


//unsigned int mod_exp(unsigned int x, unsigned int n, unsigned int m)
//{
//	unsigned int a = 1;
//	unsigned int b = x;
//	while (1)
//	{
//		unsigned int Prime = n;
//		if (n & 1) a = a * b%m ;
//		b = b * b%m;
//		n = n / 2;
//		if (Prime < 1) return a;
//	}
//	
//}
//
//int main()
//{
//	//printf("%d\n", mod_exp(3, 5, 4));
//	printf("%d\n", mod_exp(3248, 1625, 3251));
//	return 0;
//}

/*测试速度代码块
int a = 0, b = 0, c = 0, d = 0;
clock_t tstart, tend;
int times = 10000;
//scanf_s("%d,%d", &a, &d);
a = 36, b = 235;
//int Div=Euclidean_nonRecursion(a, b);
//ExtGCD(a, b,c, d);
//printf("%d=%d*%d + %d*%d\n", Div, a, c, b, d);
//printf("the Answer is: %d",a*c+b*d);

tstart = clock();
for (; a < times; a++, b++)
{
	ModExp(a, b, 10);
}
tend = clock();
printf("the Time is: %f\n", (double)(tend - tstart) / CLOCKS_PER_SEC);

a = 36, b = 235;
tstart = clock();
for (; a < times; a++, b++)
{
	TModexp(a, b, 10);
}
tend = clock();
printf("the Time is: %f", (double)(tend - tstart) / CLOCKS_PER_SEC);
getchar();

*/