#include "pch.h"
#include <iostream>

bool IsPrime_1( int num)			//	0 is not Prime
{
	for (int i = 2; i <num; i++)
	{
		if (num%i == 0) return 0;
	}
	return 1;
}

bool IsPrime_2(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <tmp; i++)
	{
		if (num %i == 0) return 0;
	}
	return 1;
}


bool IsPrime_3(int num)
{
	//两个较小数另外处理
	if (num == 2 || num == 3)
		return 1;
	//不在6的倍数两侧的一定不是质数
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//在6的倍数两侧的也可能不是质数
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//排除所有，剩余的是质数
	return 1;
}

//欧几里德算法
int Euclidean_nonRecursion(int a, int b) {
	int temp = 0;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (a%b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}

int main()
{
	int a = 0,b=0,temp=0;
	int num = 0;
	int times = 1000000;
	clock_t start = 0;
	clock_t last = 0;
	int r = 0;
	printf("请输入两个数(a,b)：\n");
	scanf("%d,%d", &a,&b);
	printf("最大公约数为：%d\n", Euclidean_nonRecursion(a,b));
	return 0;
}


