#include <bits/stdc++.h>
using namespace std;

//辗转相除法求最大公约数
//对gcd(a, b)
//当b == 0时，a即为两个数的最大公约数
//否则，求gcd(b, a%b)
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);//尾递归
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b);
    return 0;
}
