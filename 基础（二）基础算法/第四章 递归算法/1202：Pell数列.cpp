#include<bits/stdc++.h>
using namespace std;
//˼·��k�ķ�Χ��10^6����ô�����㷨��ʱ�临�Ӷ�ֻ����O(n)
//�����鷨������֧�ֶ����a_n�������ظ����� 
int a[1000005]; 
int pell(int n)
{
	if(a[n] == 0)
	{
		a[n] = (2*pell(n-1) + pell(n-2))%32767;
	}
	return a[n];
}
int main()
{
	int n, k;
	cin>>n;
	a[1] = 1;
	a[2] = 2;
	for(int i = 0; i < n; ++i)
	{
		cin>>k;
		cout<<pell(k)<<endl;
	}
}
