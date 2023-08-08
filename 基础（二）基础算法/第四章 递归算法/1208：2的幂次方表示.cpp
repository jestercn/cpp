#include <bits/stdc++.h>
using namespace std;
//二进制按位权展开

void showByTwo(int val)
{
    if(val == 0)
    {
        cout<<'0';
        return;
    }
    int m = 0, highVal = 1;//m记录val转化成的二进制数的位数, highVal记录最高次幂的值
    for(int a = val; a > 0; a /= 2)
        m++;
    for(int i = 0; i < m - 1; ++i)//展开后，最高次幂项的指数为m-1，获取最高次幂的值
        highVal *= 2;
    cout<<"2";
    if(m - 1 != 1)//输出2的指数，如果指数是1，则不输出。不是1
    {
        cout<<'(';
        showByTwo(m - 1);
        cout<<')';
    }
    if(val > highVal)//输出后面加的数字
    {
        cout<<'+';
        showByTwo(val - highVal);//原值减去最高次幂的值，对剩下的数字再进行拆分
    }
}

int main()
{
    int n;
    cin>>n;
    showByTwo(n);
    return 0;
}
