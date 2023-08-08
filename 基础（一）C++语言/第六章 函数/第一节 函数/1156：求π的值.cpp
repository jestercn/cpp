#include<bits/stdc++.h>
using namespace std;
//求arctan(x),小于1e6的那项不加进去 
double arctan(double x)
{
    double sum = 0, temp = x;
    for(int i = 1; fabs(temp / i) >= 1e-6; i += 2)//最后一项绝对值大于等于10^(-6)时进行循环
    {
        sum += temp / i;//累加各项
        temp = - x * x * temp;//求下一项
    }
    return sum;
} 
int main()
{
    cout<<fixed<<setprecision(10)<<6*arctan(1/sqrt(3)); 
    return 0;
}

