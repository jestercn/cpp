#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int m, n, a[105][105], r[105][105]={};
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>a[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
        	r[j][i] = a[i][j];
        }
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout<<r[i][j]<<' ';
        cout<<endl;
    }
} 
