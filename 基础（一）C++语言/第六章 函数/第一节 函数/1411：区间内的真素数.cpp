#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num)
{
    if(num < 2)
        return false;
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

//Êý×Ö·´Ðò
int rev(int num)
{
    int a = num;
    int res = 0;
    while(a > 0)
    {
        res *= 10;
        res += a % 10;
        a /= 10;
    }
    return res;
}

int main()
{
    int m, n;
    cin>>m>>n;
    bool isFirst = true;
    for(int i = m; i <= n; ++i)
    {
        if(isPrime(i) && isPrime(rev(i)))
        {
            if(isFirst == false)
                cout<<',';
            else
                isFirst = false;
            cout<<i;
        }
    }
    if(isFirst)
        cout<<"No";
    return 0;
}
