#include<bits/stdc++.h>
using namespace std;
//顺时针旋转90度，即上面转到右面，右面转到下面，下面转到左面，左面转到上面
//即第一行变成最后一列，第二行变成倒数第二列。。。最后一行变成第一列  
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
        	b[j][n - 1 - i] = a[i][j];//转换后的行号是原来的列号，转换后的列号是原来最大行数减去行号 
        }
        
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout<<b[i][j]<<' ';
        cout<<endl;
    }
}
 
