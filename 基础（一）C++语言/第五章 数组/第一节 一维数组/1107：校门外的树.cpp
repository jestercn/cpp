#include <bits/stdc++.h>
using namespace std;
//用数组模拟各棵树 
int main()
{
    bool a[10005];//如果位置i有树，a[i]保存为true，否则保存为false
	int l, m, start, end, s = 0;
	cin>>l>>m;
	for(int i = 0; i <= l; ++i)//a[0]~a[m]先设为有树 
		a[i] = true;
	for(int i = 0; i < m; ++i)
	{
		cin>>start>>end;
		for(int j = start; j <= end; ++j)//a[start]到a[end]设为无树 
			a[j] = false;
	}
	for(int i = 0; i <= l; ++i)
	{
		if(a[i])
			s++;
	}
	cout<<s;
    return 0;
}
