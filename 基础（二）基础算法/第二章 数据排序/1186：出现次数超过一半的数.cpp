#include <bits/stdc++.h>
using namespace std;
//˼·��ɢ�д洢 
//����ֵ�ķ�Χ��-50~50 
//ֵתΪ��ַ��ֵ+50
//��ַתΪֵ����ַ-50 
int main()
{
	int numArr[105]={}, n, num;//numArr[i+50] = j ��������i��j��
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		numArr[num+50]++;
	}
	for(int i = 0; i < 100; ++i)
	{
		if(numArr[i] > n/2)
		{
			cout<<i - 50;
			return 0;
		}
	}
	cout<<"no";
	return 0;
}
