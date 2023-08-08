#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[15], h, c=0;
    for(int i = 0; i < 10; ++i)
        cin>>a[i];
    cin>>h;
    for(int i = 0; i < 10; ++i)
    {
        if(h+30 >= a[i])//人高加上凳子高，要高过苹果高度，才能摘到 
            c++;
    }
    cout<<c;
    return 0;
}
