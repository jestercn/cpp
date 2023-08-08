#include <bits/stdc++.h>
using namespace std;

int methodCount;//走的方法数

//走n级台阶
void walk(int n)
{
    if(n == 0)//如果没有可走的台阶，说明n级台阶走完了，走法加一
        methodCount++;
    else
    {
        if(n >= 2)
            walk(n - 2);//走两级
        if(n >= 1)
            walk(n - 1);//走一级
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        methodCount = 0;
        walk(n);
        cout<<methodCount<<endl;
    }
    return 0;
}
