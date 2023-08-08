#include<bits/stdc++.h>
using namespace std;
//只买一种包装
//设一种包装的单价为x，笔的数量为y，购买这种笔m包，已知需要总笔数为n，
//有y * m >= n  即  m >= n / y， 可知m的最小值为 n/y向上取整，即ceil(n/y)
//最少花钱数为ceil(n/y) * x
//比较三种方案的最少花钱数，将最少的花钱数输出。

int main()
{
    int n, x[3], y[3], m[3], mi = INT_MAX;//mi:最少花钱
    cin>>n;
    for(int i = 0; i < 3; ++i)//y表示笔的数量，x表示笔的单价
        cin>>y[i]>>x[i];
    for(int i = 0; i < 3; ++i)
    {
        int m = ceil(double(n) / y[i]) * x[i];
        if(m < mi)
            mi = m;
    }
    cout<<mi<<endl;
    return 0;
}
