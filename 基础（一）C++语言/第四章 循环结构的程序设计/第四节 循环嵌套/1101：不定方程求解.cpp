#include <bits/stdc++.h>
using namespace std;
//对不定方程ax+by = c
//a,b,c都是正整数，x,y必须是非负整数解
//那么可以使用暴力法，x，y分别从0循环到c，看看ax+by的结果是否等于c
int main()
{
    int a, b, c, count = 0;
    cin>>a>>b>>c;
    for(int x = 0; x <= c; ++x)
        for(int y = 0; y <= c; ++y)
        {
            if(a*x + b*y == c)
                count++;
        }
    cout<<count;
    return 0;
}

