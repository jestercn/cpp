#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s = 1, num = 1;//sΪ�Ӻͣ�numΪÿһ���ֵ
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        num /= i;
        s += num;
    }
    cout<<fixed<<setprecision(10)<<s;
    return 0;
}
