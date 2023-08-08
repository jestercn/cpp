#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s = 1, num = 1;//s为加和，num为每一项的值
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        num /= i;
        s += num;
    }
    cout<<fixed<<setprecision(10)<<s;
    return 0;
}
