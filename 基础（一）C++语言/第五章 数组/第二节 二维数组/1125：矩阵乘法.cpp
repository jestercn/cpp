#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int m, n, k, s = 0, a[105][105], b[105][105], r[105][105]={};
    cin>>n>>m>>k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>a[i][j];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < k; ++j)
            cin>>b[i][j];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < k; ++j)
        {
        	for(int x = 0; x <= m-1; ++x)//¹«Ê½£ºr[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + ... + a[i][m-1] * b[m-1][j]
        		r[i][j] += a[i][x] * b[x][j];
        }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < k; ++j)
            cout<<r[i][j]<<' ';
        cout<<endl;
    }
} 
