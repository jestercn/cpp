#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
	for(int i = 2; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

//�ж�n�Ƿ��ǻ������� 
bool isHuiwen(int n)
{
	int newNum = 0;//����n��������֣���n�����������n��ȣ���ôn����һ�������� 
	for(int a = n; a > 0; a /= 10)
	{
		newNum = newNum * 10 + a % 10;
	}
	return n == newNum;
}

int main()
{
	for(int i = 100;i <= 999; ++i)
	{
		if(isPrime(i) && isHuiwen(i))
			cout<<i<<endl;
	}
	return 0;
}
