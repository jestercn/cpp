#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[505], temp, i_a = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)//������������е������������������� 
	{
		cin>>temp;
		if(temp % 2 == 1)
			a[i_a++] = temp; 
	}
	int len_a = i_a;//����a�ĳ��� 

	for(int i = 0; i < len_a-1; ++i)//����ѡ������ 
	{
		for(int j = i+1; j < len_a; ++j)
		{
			if(a[j] < a[i])
				swap(a[i], a[j]);
		}
	}
	
	cout<<a[0];//��Ŀ��֤�ˣ���������1������ 
	for(int i = 1; i < i_a; ++i)
	{
		cout<<','<<a[i];
	}
	return 0;
}
