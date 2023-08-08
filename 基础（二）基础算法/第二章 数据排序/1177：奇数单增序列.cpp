#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[505], temp, i_a = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)//把输入的数字中的奇数挑出来构成数组 
	{
		cin>>temp;
		if(temp % 2 == 1)
			a[i_a++] = temp; 
	}
	int len_a = i_a;//数组a的长度 

	for(int i = 0; i < len_a-1; ++i)//采用选择排序 
	{
		for(int j = i+1; j < len_a; ++j)
		{
			if(a[j] < a[i])
				swap(a[i], a[j]);
		}
	}
	
	cout<<a[0];//题目保证了，至少由于1个奇数 
	for(int i = 1; i < i_a; ++i)
	{
		cout<<','<<a[i];
	}
	return 0;
}
