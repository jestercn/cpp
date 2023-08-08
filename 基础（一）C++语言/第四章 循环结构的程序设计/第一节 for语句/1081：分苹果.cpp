#include<bits/stdc++.h>
using namespace std;
/*问题抽象：n个整数，都大于0，n个数不同，求这n个数的和的最小值
显然：当这n个数为1,2,3,...,n时，和最小。
问题可以转化为求1+2+...+n的和 
*/
int main()
{
	int n, s = 0;
	cin>>n;
	for(int i = 1; i <= n; ++i)
		s += i;
	cout<<s;
	return 0;
}
