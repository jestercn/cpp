#include <bits/stdc++.h>
using namespace std;
//���鷨����쳲��������и��Ȼ���ѯ 
int a[1000005];
int main()
{
	a[1] = a[2] = 1;
	for(int i = 3; i <= 1000000; ++i)
		a[i] = (a[i-1] + a[i-2])%1000;
	int n, x; 
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		cout<<a[x]<<endl;
	}
	return 0;
}
