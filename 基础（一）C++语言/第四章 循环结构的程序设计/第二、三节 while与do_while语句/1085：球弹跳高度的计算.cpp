#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h;
    cin>>h;
    double sum = h;//第一次球落地，经过距离h 
    for(int i = 2; i <= 10; ++i)//i表示第几次落地 
    {
        h /= 2;//h表示这次落地后弹起的高度 
        sum += 2 * h;//每次球从弹起到落地，经过距离2h 
    }
    cout<<sum<<endl<<h/2<<endl;
    return 0;
}
