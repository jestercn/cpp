#include<bits/stdc++.h>
using namespace std;
//第1阶段，国王每天给1个金币；第2阶段，国王每天给2个金币；以此类推
int main()
{
    int n;
    cin>>n;
    int sum = 0, d = 1, j = 1;//d：当前在第几阶段, j：在这一阶段第几天
    for(int i = 1; i <= n; ++i)//i：当前处于第几天
    {
        sum += d;
        if(j >= d) //如果已经达到第d阶段的第d天，那么该进行下一阶段
        {
            d++;
            j = 1;
        }
        else
            j++;
    }
    cout<<sum;
}
