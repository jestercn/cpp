#include<bits/stdc++.h>
using namespace std;
//如果a>=b, a/b = (mb+ r)/b = m + r/b, 满足r<b, 其中m为a/b(整除运算), r为a%b 
//求小数位，用r/b就能求出
//而后模拟除法竖式的计算过程
//每次被除数r都会乘以10，除以除数b后，商是这一位小数的数字d，剩下余数r%b作为下一次除运算的被除数 
int main()
{
	int a, b, n;
	cin>>a>>b>>n;
	int r = a%b;
	int d;//d为某一位的小数 
	for(int i = 1; i <= n; ++i)
	{
		r *= 10;
		d = r/b;
		r %= b;
	} 
	cout<<d;
	return 0;
}
