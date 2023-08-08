#include<bits/stdc++.h>
using namespace std;
/*求(a^b)%1000
根据(a*b)%c = (a%c*b%c)%c
(a*b*c)%d = ((a*b)%d*c%d)%d = ((a%d*b%d)%d*c%d)%d;
由此也可以导出 (a^b)%1000 = ((a%1000)^b)%1000 = ((a%1000 * a%1000)%1000 * (a%1000)^b-2)%1000 
也就是说，n个数相乘对1000取模，可以将相乘的所有数字取模，两个取模后的数字相乘后再取模
保存结果的量每乘一次后就做一次取模 
*/ 
int main()
{
	int a, b, s = 1;
	cin>>a>>b;
	a %= 1000;
	for(int i = 0; i < b; ++i)
	{
		s = (s*a)%1000;
	}
	if(s<10)
		cout<<"00";
	else if (s < 100)
		cout<<'0';
	cout<<s;
	return 0;
}
