#include<bits/stdc++.h>
using namespace std;
//��ð����������� ���ݽ����Ĵ��� 
int main()
{
	int n, a[10005], t = 0;//t�����ݽ����Ĵ��� 
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}	
	for(int i = 0; i <= n-2; ++i)
	{
		for(int j = 0; j <= n-2-i; ++j)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				t++;
			}
		}
	}
	cout<<t;
	return 0; 
}
