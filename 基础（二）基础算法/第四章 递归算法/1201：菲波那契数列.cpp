#include <bits/stdc++.h>
using namespace std;
//����ǵ�1,2�����1�����򣬷���ǰ����ĺ� 
int fib(int i)
{
	if(i <= 2)
		return 1;
	else
		return fib(i-1) + fib(i-2);
}
int main()
{
	int n, a;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		cout<<fib(a)<<endl;
	}
	return 0;
}
