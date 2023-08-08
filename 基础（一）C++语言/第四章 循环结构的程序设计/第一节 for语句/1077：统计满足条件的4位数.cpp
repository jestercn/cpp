#include<bits/stdc++.h>
using namespace std;
bool isOk(int n)//是否满足条件 
{
    int d = n % 10;//取个位 
    n /= 10;
    while(n>0)
    {
        d -= n%10;//个位的值不断减去其他位的值 
        n /= 10;
    }
    return d > 0;//个位的值减去所有其他位的值后是否大于0 
}

int main()
{
   int n, s=0;
   cin>>n;
   for(int i = 0; i < n; ++i)
   {
        int a;
        cin>>a;
        if(isOk(a))
            s++;
   }
   cout<<s;
}
