#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m, a[105][105], b[105][105];
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>a[i][j];
 
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(i == 0 || i == n-1 || j == 0 || j == m-1)//四周灰度值不变 
                b[i][j] = a[i][j];
            else
                b[i][j] = round((a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1] + a[i][j])/5.0);//中心的位置灰度值是上下左右数字的平均 
        }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
            cout<<b[i][j]<<' ';
        cout<<endl;
    }
}
 
