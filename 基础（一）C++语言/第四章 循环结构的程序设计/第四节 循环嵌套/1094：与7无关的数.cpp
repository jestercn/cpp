#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        if (i % 7 == 0)//如果是7的倍数，那么与7有关
            continue;//与7有关，那么重新开始循环，看下一个数i
        int m = i;
        bool isRelevant = false;//标志位 表示是否与7有关
        while(m > 0)//取数字的各个数位
        {
            if (m % 10 == 7)
            {
                isRelevant = true;
                break;
            }
            m /= 10;
        }
        if (isRelevant)//如果相关，那么看下一个数
            continue;
        sum += i * i;//如果无关，把i*i加到sum中
    }
    cout<<sum<<endl;
    return 0;
}

/*
bool isRel7(int n)//用函数实现，判断一个数是否与7有关
{
    if(n%7 == 0)
        return true;
    int a = n;
    while(a>0)
    {
        int d = a % 10;
        if(d == 7)
            return true;
        a /= 10;
    }
    return false;
}

int main()
{
    int n, s = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        if(isRel7(i) == false)
            s += i * i;
    }
    cout<<s;
    return 0;
}
*/
