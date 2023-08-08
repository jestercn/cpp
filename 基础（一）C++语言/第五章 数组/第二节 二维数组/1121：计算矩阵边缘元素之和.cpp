#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, a[101][101];
    cin>>m>>n;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin>>a[i][j];
    int sum = 0;
    for(int j = 0; j < n; ++j) 
    {
        sum += a[0][j];//计算第1行的和 
        if (0 != m-1)//如果矩阵并非只有1行，计算最后一行的和 
            sum += a[m-1][j];
    }
    for(int i = 1; i < m-1; ++i)
    {
        sum += a[i][0];//计算第1列除了上下两端元素，的和 
        if (0 != n-1)//如果矩阵并非只有1列，计算最后一列除了上下两端元素的和 
            sum += a[i][n-1];
    }
    cout<<sum;
    return 0;
}
