#include <bits/stdc++.h>
using namespace std;
//判断num是否是质数 
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

//判断num是否是回文数
bool isPal(int num)
{
    int s[6], i = 0;
    int a = num;
    while(a > 0)
    {
        s[i++] = a % 10;
        a /= 10;
    }
    //此时 i的值是num的位数
    for(int j = 0; j < i/2; ++j)
    {
        if(s[j] != s[i-1-j])
            return false;
    }
    return true;
}

int main()
{
    int n, s = 0;
    cin>>n;
    for(int i = 11; i <= n; ++i)
    {
        if(isPrime(i) && isPal(i))
            s++;
    }
    cout<<s;
    return 0;
}
