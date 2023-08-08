#include <bits/stdc++.h>
using namespace std;
  
int main()
{
	double a, b, c, d, x;
	cin>>x>>a>>b>>c>>d;
	cout<<fixed<<setprecision(7)<<x*(x*(a*x+b)+c)+d;//用秦九韶算法，减少相乘次数，也减少输入的表达式长度 
	return 0;
}

