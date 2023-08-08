#include <bits/stdc++.h>
using namespace std;

double h(int n, int x)
{
    if(n == 0)
        return 1;
    else if(n == 1)
        return 2*x;
    else
        return 2*x*h(n-1, x)-2*(n-1)*h(n-2, x);
}

int main()
{
    int x, n;
    cin>>n>>x;
    cout<<fixed<<setprecision(2)<<h(n, x); 
	return 0;
}
