#include<bits/stdc++.h>
using namespace std;
//由于n能达到10^9，所以不能真的从头到尾遍历n，只能先找到它的两个相乘质数中较小的那个质数
int main()
{
    int n;
    cin>>n;
    for(int i = 2; i <= n-1; ++i)
    {
        if(n%i == 0)//此时i是n的一个因数，根据题意，此时i一定是两个相乘的质数中较小的那个质数
        {
            cout<<n/i<<endl;//根据题意，n是由两个质数相乘得到的，那么n/i就是另一个较大的质数
            return 0;
        }
    }
    return 0;
}
