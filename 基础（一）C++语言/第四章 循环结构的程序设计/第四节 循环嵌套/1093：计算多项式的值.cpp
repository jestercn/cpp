#include <bits/stdc++.h>
using namespace std;
//���ؾ����㷨 ���Լ���ʱ�临�Ӷȵ�O(n)
//�磺x^2+x+1 = x(x+1)+1
int main()
{
    double x, s = 1;
    int n;
    cin>>x>>n;
    for(int i = 0; i < n; ++i)
    {
        s = x * s + 1;
    }
    cout<<fixed<<setprecision(2)<<s;
    return 0;
}
