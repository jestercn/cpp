#include<bits/stdc++.h>
using namespace std;
//������n������֮�� ���Ӳ�����n���� 
int sumOfFactor(int n)
{
	int s = 0;
	for(int i = 1; i < n; ++i)
	{
		if(n % i == 0)//���i��n������ 
			s += i;
	}
	return s;
}

int main()
{
	int a, b;
	for(int i= 2; true; ++i)
	{
		a = i;
		b = sumOfFactor(a);
		if(a != b && a == sumOfFactor(b))
		{
			if(a < b)
				cout<<a<<' '<<b;
			else
				cout<<b<<' '<<a;
			break;
		}
	}
	return 0;
}
