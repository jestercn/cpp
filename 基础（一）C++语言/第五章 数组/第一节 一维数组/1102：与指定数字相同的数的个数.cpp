#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[105], n, m, c = 0;//c£º¼ÆÊý 
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    cin>>m;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == m)
            c++;
    }
    cout<<c<<endl;
    return 0;
}
