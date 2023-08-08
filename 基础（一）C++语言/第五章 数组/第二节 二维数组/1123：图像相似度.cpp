#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int m, n, s = 0, a[105][105], b[105][105];
    cin>>m>>n;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin>>a[i][j];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin>>b[i][j];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(a[i][j] == b[i][j])
                s++;
        }
    cout<<fixed<<setprecision(2)<<(double)s/(m*n)*100;
} 
