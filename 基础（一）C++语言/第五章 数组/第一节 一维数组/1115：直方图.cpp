#include <bits/stdc++.h>
using namespace std;
//ɢ�д洢 �����ֵ 
int main()
{
	int a[10005]={}, n, num, fmax = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &num);//��cin�ᳬʱ 
		a[num]++;
		if(num > fmax)
			fmax = num;
	}
	for(int i = 0; i <= fmax; ++i)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
