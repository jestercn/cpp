#include<bits/stdc++.h>
using namespace std;

void insertSort(int a[], int n, bool isUp)//isUp是否是升序 
{
	bool isChange;//是否交换 
	for(int i = 1; i < n; ++i)
	{
		for(int j = i; j >=1; --j)
		{
			if(isUp)
				isChange = a[j] < a[j-1];
			else
				isChange = a[j] > a[j-1];
			if(isChange)
				swap(a[j], a[j-1]);
			else
				break;
		}
	}
}

int main()
{
	int num, a_o[15], a_e[15], l_o = 0, l_e = 0;//a_o用于排序奇数 a_e用于排序偶数 l_o：a_o的长度 l_e:a_e的长度 
	for(int i = 0; i < 10; ++i)
	{
		cin>>num;
		if(num % 2 == 1)
			a_o[l_o++] = num;
		else
			a_e[l_e++] = num;
	}
	insertSort(a_o, l_o, false);
	insertSort(a_e, l_e, true);
	for(int i = 0; i < l_o; ++i)
		cout<<a_o[i]<<' ';
	for(int i = 0; i < l_e; ++i)
		cout<<a_e[i]<<' ';
}
