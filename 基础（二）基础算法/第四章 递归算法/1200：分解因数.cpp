#include <bits/stdc++.h>
using namespace std;
//思路：对于数a，从2循环到a，寻找a能整除的数，如果存在x能被a整除，那么对数字a/x进行因数搜索,搜索的起始数字是x。 
//如果a/x == 1,那么找到一组分解，分解的数量加1
//例：对数6进行因数搜索 
//循环到2：2能被6整除，6/2=3
//    对3进行因数搜索 
//    从2循环到3：3能被3整除，3/3==1 找到一组分解，为2*3
//循环到3：3能被6整除，6/3 = 2
// 	   对2进行因数搜索，从3开始，无法进行，返回 
//循环到6:6能被6整除，6/6 == 1，找到一组分解

int ct; //计数 
//寻找数a的因数,搜索的起始数字是start 
void Search(int a, int start)
{
	if(a == 1)//如果寻找到一组因数分解，那么计数加一 
		ct++;
	else
	{
		for(int i = start; i <= a; ++i)
		{
			if(a%i == 0)
				Search(a/i, i);  
		}
	}
}

int main()
{
	int n, a;
	cin>>n;
	for(int i = 0;i < n; ++i)
	{
		cin>>a;
		ct = 0;
		Search(a, 2);
		cout<<ct<<endl;
	}
	return 0;
}
