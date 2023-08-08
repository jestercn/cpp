#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a)
{
    if(a == 2)
        return true;
    if(a % 2 == 0 || a < 2)
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
    int c = 0, x, y;
    cin>>x>>y;
    if(x > y)//注意：题目中并没有确定y大于x，所以我们要手动保持让y大于x 
        swap(x, y);
    for(int i = x; i <= y; ++i)
    {
        if(isPrime(i))
            c++;
    }
    cout<<c;
}
