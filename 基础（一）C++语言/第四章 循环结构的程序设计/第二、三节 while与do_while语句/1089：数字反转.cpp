#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n < 0)//如果该数字小于0，那么输出负号，并将该数字变为正数
    {
        cout<<'-';
        n = -n;
    }
    bool isPreZero = true;//标志位，现在是否处于输出前面的0的状态
    while(n > 0)
    {
        int d = n%10;
        n /= 10;
        if(isPreZero)//如果处于输入前面的0的状态
        {
            if(d == 0)//且这一数字为0
                continue;//那么不输出，重新开始循环
            else
                isPreZero = false;//否则，输出前面的0的状态结束
        }
        cout<<d;
    }
    return 0;
}
