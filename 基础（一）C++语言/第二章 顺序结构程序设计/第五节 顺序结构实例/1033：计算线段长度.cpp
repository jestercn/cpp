#include <bits/stdc++.h>
using namespace std;

int main()
{
	double xa, ya, xb, yb;
	cin>>xa>>ya>>xb>>yb;
	cout<<fixed<<setprecision(3)<<sqrt(pow(xa-xb,2) + pow(ya-yb,2));//两点距离公式：根号下((xa-xb)的平方 加上 (ya-yb)的平方)
	//cmath中的函数：sqrt(x)：对x开根号，pow(a,b)求a的b次方 
	return 0;
}

