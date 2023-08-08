#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l, r, c = 0;
    cin>>l>>r;
    for(int i = l; i <= r; ++i)
    {
        for(int a = i; a > 0; a/=10)
        {
            int d = a % 10;
            if (d == 2)
                c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
