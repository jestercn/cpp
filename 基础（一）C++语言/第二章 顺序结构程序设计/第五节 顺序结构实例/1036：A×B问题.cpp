#include <bits/stdc++.h>
using namespace std;
//已知1<=a,b<=50000，a*b的值可能达到2.5e9，可能超出int能表示的范围。
//所以要用能表示的数字的范围更大的类型long long 来声明变量。 
int main()
{
	long long a, b;
	cin>>a>>b;
	cout<<a*b;
	return 0;
}

