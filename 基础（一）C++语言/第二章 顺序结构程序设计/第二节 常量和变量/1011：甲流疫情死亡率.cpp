#include <bits/stdc++.h>
using namespace std;
//保留x位小数的写法：
//cout<<fixed<<setprecision(x)<<...
//printf("%.xd", ...);  
int main()
{
	double a, b;
	cin>>a>>b;
	cout<<fixed<<setprecision(3)<<b/a*100<<'%';
	//printf("%.3f%%", b/a*100); //printf输出一个百分号字符，要打两个% 
	return 0;
}

