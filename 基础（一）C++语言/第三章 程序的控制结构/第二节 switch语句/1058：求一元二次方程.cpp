#include<bits/stdc++.h>
using namespace std; 
int main()
{
  	double a, b, c;
  	cin>>a>>b>>c;
  	double m = b*b - 4*a*c;
  	if(fabs(m) < 0.00001)
		cout<<"x1=x2="<<fixed<<setprecision(5)<<-b/(2*a);
	else if(m > 0)
	{
		double x_small = (-b-sqrt(m))/(2*a);
		double x_big = (-b+sqrt(m))/(2*a);
		if(x_small > x_big)
		{
			double temp = x_small;
			x_small = x_big;
			x_big = temp;
		}		
		cout<<fixed<<setprecision(5)<<"x1="<<x_small<<";x2="<<x_big;
	}
	else
		cout<<"No answer!";
    return 0;
}
