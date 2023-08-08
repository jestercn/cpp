#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum = 0, num = 1;//numÎªi!µÄÖµ
    for(int i = 1; i <= n; ++i)
    {
        num *= i;
        sum += num;
    }
    cout<<sum;
    return 0;
}
