#include <bits/stdc++.h>
using namespace std;

/*小学数学应用题 二元一次方程组问题 
设地球每年新生资源为n,已有资源为m, 1亿人每年消耗资源p 
则有方程组： 
x*p*a = m + a*n
y*p*b = m + b*n
使资源不枯竭，每年消耗的资源必须小于等于再生的资源，有 
z*p <= n
即z <= n/p 地球最多能养活的人口数即为n/p 
方程组两边除以p，得： 
x*a = m/p + a*n/p
y*b = m/p + b*n/p
两方程相减，得： 
x*a - y*b = (a-b)n/p
n/p = (x*a - y*b)/(a-b)
*/ 
//保留x位小数的写法：
//cout<<fixed<<setprecision(x)<<...
//printf("%.xd", ...); 
int main()
{
	int x,y,a,b;
	cin>>x>>a>>y>>b;
	//值为整型的表达式相除，会进行整除运算。若想得到实数结果，必须把其中一个表达式的值强转为浮点型 
	cout<<fixed<<setprecision(2)<<(double)(x*a - y*b)/(a-b); 
	return 0;
}

