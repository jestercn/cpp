#include <bits/stdc++.h>
using namespace std;

int main()
{
	int max, min, n, a;
	cin>>n;
	cin>>a;
	max = min = a;//�Ȱ������Сֵ��Ϊ��һ��ֵ 
	for(int i = 1; i < n; ++i)//ѭ��n-1�Σ�������������� 
	{
		cin>>a;
		if(a > max)
			max = a;
		if(a < min)
			min = a;
	}
	cout<<max-min;
	return 0;
}
