#pragma once
#include"pch.h"

bool IsPrime(unsigned long int num);									//判断素数
int Euclidean_nonRecursion(int a, int b);				//辗转相除法
unsigned long long gcd(unsigned long long a, unsigned long long b);								//辗转相除法迭代

//拓展欧几里德算法，(a,mod,a^-1,y)
long long ExtGCD(long long a, long long b, long long &x, long long &y);				//拓展欧几里德算法
unsigned long long ModExp(unsigned long long base, unsigned long ex, unsigned long long mod);			//模的指数运算,计算x^y(modN)
int TModexp(int x, int y, int N);

//取2~n-2互不相同的随机数,输入（数组,n为被测数字）
void randarry(long unsigned int *arry, long unsigned int n);		

//素数的概念性检验算法,l为范围[10^l~10^(l+1)]，k为轮转次数,如果找到素数则返回该素数，否则返回0；
long unsigned int F(int l, int k);

void Miller(unsigned long long n, unsigned long long int a);

unsigned long long int MI(int a, int b);				//指数运算