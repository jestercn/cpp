#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int m, n, s = 0, a[105][105], b[105][105], r[105][105];
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>a[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>b[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            r[i][j] = a[i][j] + b[i][j];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cout<<r[i][j]<<' ';
        cout<<endl;
    }
} 
