#pragma once
#include"pch.h"

bool IsPrime(unsigned long int num);									//�ж�����
int Euclidean_nonRecursion(int a, int b);				//շת�����
unsigned long long gcd(unsigned long long a, unsigned long long b);								//շת���������

//��չŷ������㷨��(a,mod,a^-1,y)
long long ExtGCD(long long a, long long b, long long &x, long long &y);				//��չŷ������㷨
unsigned long long ModExp(unsigned long long base, unsigned long ex, unsigned long long mod);			//ģ��ָ������,����x^y(modN)
int TModexp(int x, int y, int N);

//ȡ2~n-2������ͬ�������,���루����,nΪ�������֣�
void randarry(long unsigned int *arry, long unsigned int n);		

//�����ĸ����Լ����㷨,lΪ��Χ[10^l~10^(l+1)]��kΪ��ת����,����ҵ������򷵻ظ����������򷵻�0��
long unsigned int F(int l, int k);

void Miller(unsigned long long n, unsigned long long int a);

unsigned long long int MI(int a, int b);				//ָ������