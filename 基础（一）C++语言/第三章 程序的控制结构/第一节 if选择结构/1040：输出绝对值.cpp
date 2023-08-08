#include<bits/stdc++.h>
using namespace std;
//用if语句来做，练习if语句，不用fabs() 
int main()
{
	double a;
	cin>>a;
	if(a < 0)
		a = -a;
	cout<<fixed<<setprecision(2)<<a;
	return 0;
}
