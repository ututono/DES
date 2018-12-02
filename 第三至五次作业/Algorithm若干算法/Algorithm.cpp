#include"pch.h"
#include"Algorithm.h"

bool IsPrime(unsigned long int num)
{
	//������С�����⴦��
	if (num == 2 || num == 3)
		return 1;
	//����6�ı��������һ����������
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	unsigned long int tmp = sqrt(num);
	//��6�ı��������Ҳ���ܲ�������
	for (unsigned long int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//�ų����У�ʣ���������
	return 1;
}

int Euclidean_nonRecursion(int a, int b)
{
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
unsigned long long gcd(unsigned long long a, unsigned long long b) {
	unsigned long long temp = 0;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	return b ? gcd(b, a%b) : a;
}

//��չŷ������㷨
 long long ExtGCD( long long a,  long long b,  long long &x,  long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		long long r = ExtGCD(b, a%b, y, x);						//����x��yλ��
		y = y - (a / b)*x;
		return r;
	}
}

//ģָ����
unsigned long long ModExp(unsigned long long base, unsigned long ex, unsigned long long mod)
{
	unsigned long long result = 1;
	base = base % mod;
	while (ex > 0) 
	{
		if (ex%2==1) result = (result*base) % mod;
		ex = ex / 2;
		unsigned long long temp = base * base;			//��base>2^32=42,9496,7296,�˷��������
		base = (base*base) % mod;
	}
	return result;
 }


////ģָ����
//unsigned int ModExp(unsigned int x,unsigned int n, long unsigned int m)
//{
//		unsigned int a = 1;
//		unsigned int b = x;
//		while (n>0)
//		{
//			unsigned int temp = n;
//			if (n & 1) a = a * b%m ;
//			b = b * b%m;
//			n = n / 2;
//			if (temp < 1) return a;
//		}
//}


//������������
//unsigned int ModExp(unsigned int x, unsigned int y, long unsigned int N)
//{
//	if (y == 0) return 1;
//	int z = ModExp(x, y / 2, N);
//	if (y % 2 == 0) return z * z%N;
//	else return x * z*z%N;
//
//}

int TModexp(int x, int y, int N)
{
	for (int i = 0; i < y; i++)
	{
		x = x * x;
	}
	return x%N;
}

//ŷ������
int euler(int n) { //����euler(n)   
	int res = n, a = n;
	for (int i = 2; i*i <= a; i++) {//��С������n�������� 
		if (a%i == 0) {//���i��n�������� 
			res = res / i * (i - 1);//����һ��1/i�������Ƚ��г�����Ϊ�˷�ֹ�м����ݵ����   
			while (a%i == 0) a /= i;//ŷ������ֻ����һ�������� 
		}
	}
	if (a > 1) res = res / a * (a - 1);//������ʣ���� 
	return res;
}

unsigned long long int MI(int a, int b)
{
		unsigned long long r;
		unsigned long long x = a;
		unsigned long long y = 1;
		while (b != 0) {
			r = b % 2;
			b = b / 2;
			if (r == 1)
				y *= x;
			x = x * x;
		}
		return y;
}

//ȡ2~n-2������ͬ�������,���루����,nΪ�������֣�
void randarry(long unsigned int *arry,long unsigned int n)
{
	if (n < 4) return;
	long unsigned int length = n;
	n -= 2;
	for (long unsigned int i = 0; i < length-3; i++,n--)
	{
		arry[i] = n;
	}
	//ϴ���㷨
	if (n < 6) return;
	for (long unsigned int i = length - 3; i > 1;)
	{
		int random = rand() % i;
		int tmp = arry[--i];
		arry[i] = arry[random];
		arry[random] = tmp;
	}
}

bool Pass = 0;

//�ҵ�n-1�����������m��t
void Search(unsigned long long int n, int &t, unsigned long long int &m)
{
	int Max = 0;
	unsigned long long tmp = 0;
	unsigned long long MaxJ = 0;
	n--;
	for (int i = 1; i <= log2(n); i++)
	{
		tmp = (n / MI(2, i));
		if ((n % MI(2, i) == 0) && tmp % 2 != 0)		//���n�ܱ�2��ָ��������������Ϊ����
		{
			if ((n / MI(2, i)) > MaxJ)
			{
				Max = i;
				MaxJ = n / MI(2, i);
			}
		}
	}
	t = Max;
	m = MaxJ;
}

void Miller(unsigned long long n, unsigned long long int a)
{
	unsigned long long  m = 0;
	int t = 0;

	Search(n, t, m);

  	if (!(n & 1))			//����
	{
		Pass = 0;
		if (n == 2) Pass = 1;
		return;
	}
	unsigned long long b = ModExp(a, m, n);
	if (b == 1 || b == (n - 1))
	{
		Pass = 1;
		return;
	}
	Pass = 0;
	for (int j = 1; j < t ; j++)
	{
		b = ModExp(b, 2, n);
		if (b ==(n - 1))
		{
			Pass = 1;
			return;
		}
	}
}


long unsigned int F(int l, int k)
{
	
	#define MAX 1000
	unsigned long long int n;
	do {
		n = rand() % (MI(10, l + 1) + 1) +MI(10, l);
	} while (!(n&1));
	//n= rand() % (MI(10, l + 1) + 1) + MI(10, l);
	//if (n & 1); else n -= 1;				//nȡ������
	//long unsigned int *K_arry;		//K_arry�Ǵ洢2~n-2������

	int t = 0;
	long unsigned int m = 0;
	unsigned long a = 0;
	
	//K_arry = (long unsigned int *)calloc(n - 3, sizeof(long unsigned int));
	//randarry(K_arry, n);
	
	for (int i = 1; i < k; i++) 
	{
			a = rand() % (n-2) + 2;
			Miller(n, a);
			if (Pass == 0) break;
	}

	//for (int i = 1; i < k; i++)
	//{
	//	if (K_arry[i] > 1 && K_arry[i] < n - 1)
	//	{
	//		a = rand() % (n - 2) + 2;
	//		Miller(n, a);
	//		if (Pass == 0) break;
	//	}
	//}

	//free(K_arry);
	//if (IsPrime(n))

	if (Pass == 1) 
		return n;
	else return 0;
	//else printf("%dһ���Ǻ���\n", n);
}

WCHAR * ChartoUnicode(char *input, long &unicodelength) {
	long unicodelen;
	unicodelen = MultiByteToWideChar(CP_ACP, 0, input, -1, NULL, 0);
	//WCHAR *output = (WCHAR*)malloc((int)unicodelen * sizeof(WCHAR));
	WCHAR* output = new WCHAR[unicodelen];
	MultiByteToWideChar(CP_ACP, 0, input, -1, (LPWSTR)output, unicodelen);
	//delete[] output;
	unicodelength = unicodelen;
	return output;
}