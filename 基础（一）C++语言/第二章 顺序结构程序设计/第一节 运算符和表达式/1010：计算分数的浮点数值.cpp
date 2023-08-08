#include <bits/stdc++.h>
using namespace std;
//保留x位小数的写法：
//cout<<fixed<<setprecision(x)<<...
//printf("%.xd", ...);  
int main()
{
	double a, b;
	cin>>a>>b;
	cout<<fixed<<setprecision(9)<<a/b; 
	return 0;
}

