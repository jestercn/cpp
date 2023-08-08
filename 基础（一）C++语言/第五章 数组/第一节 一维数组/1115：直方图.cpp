#include <bits/stdc++.h>
using namespace std;
//散列存储 求最大值 
int main()
{
	int a[10005]={}, n, num, fmax = 0;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &num);//用cin会超时 
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
