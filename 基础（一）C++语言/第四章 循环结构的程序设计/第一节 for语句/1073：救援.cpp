#include<bits/stdc++.h>
using namespace std;
//��(x,y)��ԭ��ľ��룺sqrt(x*x+y*y) 
//����ȡ��ceil() 
int main()
{
    int n;
    double time = 0;
    cin>>n;
    double x, y, p;
    for(int i = 1; i<=n; ++i)
    {

        cin>>x>>y>>p;
        time += sqrt(x*x + y*y) / 50 * 2+ p * 1.5;
    }
    cout<<ceil(time);
}
