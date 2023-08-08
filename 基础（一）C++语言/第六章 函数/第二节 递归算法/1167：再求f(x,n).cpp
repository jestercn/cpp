#include <bits/stdc++.h>
using namespace std;

double solve(int n, double x)
{
    if(n == 1)
        return x/(1 + x);
    else
        return x/(n + solve(n-1, x));
}

int main()
{
    double x;
    int n;
    cin>>x>>n;
    cout<<fixed<<setprecision(2)<<solve(n, x); 
	return 0;
}
