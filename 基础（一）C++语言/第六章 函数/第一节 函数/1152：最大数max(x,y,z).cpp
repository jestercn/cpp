#include<bits/stdc++.h>
using namespace std;

double Max(double a, double b, double c)
{
	if(a >= b && a >= c)
		return a;
	else if(b >= a && b >= c)
		return b;
	else
		return c; 
}

int main()
{
	double a, b, c;
	cin>>a>>b>>c;
	cout<<fixed<<setprecision(3)<<Max(a, b, c) / (Max(a + b, b, c) * Max(a, b, b + c));
}
