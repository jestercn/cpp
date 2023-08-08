#include <bits/stdc++.h>
using namespace std;
//用秦九韶算法 可以减少时间复杂度到O(n)
//如：x^2+x+1 = x(x+1)+1
int main()
{
    double x, s = 1;
    int n;
    cin>>x>>n;
    for(int i = 0; i < n; ++i)
    {
        s = x * s + 1;
    }
    cout<<fixed<<setprecision(2)<<s;
    return 0;
}
