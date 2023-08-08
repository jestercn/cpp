#include<bits/stdc++.h>
using namespace std;
//判断一个数是否是质数
bool isPrime(int a)
{
    if(a == 2)
        return true;
    if(a % 2 == 0)
        return false;
    else
    {
        for(int i = 3; i <= floor(sqrt(a)); i+=2)
        {
            if(a % i == 0)
                return false;
        }
    }
    return true;
}


int main()
{
    int n, c = 0;
    cin>>n;
    for(int i = 2; ; ++i)
    {
        if(isPrime(i))
        {
            c++;
            if(c >= n)
            {
                cout<<i;
                return 0;
            }
        }
    }
}
