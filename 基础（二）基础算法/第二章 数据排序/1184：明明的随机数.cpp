#include <bits/stdc++.h>
using namespace std;
//Ͱ���� 
int main()
{
	int n, num, count = 0, a[105], a_i = 0;
	cin>>n;
	//��ɢ�д洢ȥ��
	bool hasNum[1005]={};
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		hasNum[num] = true;
	}
	for(int i = 1; i <= 1005; ++i)
	{
		if(hasNum[i])
		{
			a[a_i++] = i;
			count++; 
		}
	}
	cout<<count<<endl;
	for(int i = 0; i < a_i; ++i)
		cout<<a[i]<<' ';
}
