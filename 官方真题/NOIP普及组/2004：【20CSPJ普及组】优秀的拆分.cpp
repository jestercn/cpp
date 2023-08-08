#include<bits/stdc++.h>
using namespace std;
//十进制转二进制问题
//拆分出的数字只能是正整数次幂，那么拆分出的数字最小为2，也就是说，如果原数字是奇数就不能完成拆分。
//这是一个数制转换问题，求该数字在二进制下的按位权展开后的各项
int main()
{
	int n, a, num, res[100], r_i = 0;//num表示位权，res存储存在的各位权数字，r_i是res的下标，a是基于原数字的不断变化的数字
	cin>>n;
	if(n % 2 == 1)//如果是奇数，就不能拆分
		cout<<-1;
	else
	{
		for(a = n/2, num = 2; a > 0; a /= 2, num*=2)
		{
			if(a % 2 == 1)
				res[r_i++] = num;//将该存在的位权填入res数组中
		}
	}
	for(int i = r_i - 1; i >= 0; --i)//res是位权从低到高存储，要从高到低输出，要逆序输出
		cout<<res[i]<<' ';
	return 0;
}
