#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a[10]={28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
    float sum = 0;
    for(int i = 0; i < 10; ++i)
    {
        float num;
        cin>>num;
        sum += a[i] * num;
    }
    cout<<sum;
    return 0;
}
