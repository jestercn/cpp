#include<bits/stdc++.h>
using namespace std;
//������n������֮�� ��������Ӳ�����n����ʵ�ʰ�����ѧ�ϵĶ��壬nҲ��n�����ӡ� 
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
	int n;
	cin>>n;
	for(int i = 2; i <= n; ++i)
	{
		if(sumOfFactor(i) == i)
			cout<<i<<endl;
	}
}
