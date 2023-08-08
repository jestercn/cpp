#include<bits/stdc++.h>
using namespace std;
/*求(a^b)%7
根据(a*b)%c = (a%c*b%c)%c
(a*b*c)%d = ((a*b)%d*c%d)%d = ((a%d*b%d)%d*c%d)%d =((a%d*b%d)%d*c%d%d)%d = (a%d*b%d*c%d)%d 
由此也可以导出 (a^b)%7 = ((a%7)^b)%7 
也就是说，n个数相乘对7取模，可以将相乘的所有数字取模，两个取模后的数字相乘后再取模
保存结果的量每乘一次后就做一次取模 
*/ 
int main()
{
	int a, b, s = 1;
	cin>>a>>b;
	a %= 7;
	for(int i = 0; i < b; ++i)
	{
		s = (s*a)%7;
	}
	//从周日过了s天 
	switch(s)
	{
		case 0:
			cout<<"Sunday";
			break;
		case 1:
			cout<<"Monday";
			break;
		case 2:
			cout<<"Tuesday";
			break;
		case 3:
			cout<<"Wednesday";
			break;
		case 4:
			cout<<"Thursday";
			break;
		case 5:
			cout<<"Friday";
			break;
		case 6:
			cout<<"Saturday";
			break;
	}
	return 0;
}
