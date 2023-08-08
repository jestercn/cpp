#include <bits/stdc++.h>
using namespace std;

int main()
{
	double r;
	const double PI = 3.14;
	cin>>r;
	cout<<fixed<<setprecision(2)<<4.0/3.0*PI*r*r*r;//写成4.0/3.0，是浮点型常量相除，保证这是实数相除运算 
	return 0;
}

