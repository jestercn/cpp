#include <bits/stdc++.h>
using namespace std;

int main()
{
    int parent[101] = {}, degree[101] = {};//parent[i] 表示结点i的双亲, degree[i]表示结点i的度
    int n, m, x, y, root, maxDeg = 0, maxNum = 1;//root:表示根结点编号，maxNum:度最高结点编号，maxDeg：表示度最高结点的度，即孩子对多的结点的孩子数
    cin>>n>>m;
    for(int i = 1; i <= m; ++i)
    {
        cin>>x>>y;
        parent[y] = x;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(parent[i] == 0)
        {
            root = i;
        }
        degree[parent[i]]++;//结点i的双亲的度加1
    }
    cout<<root<<endl;
    for(int i = 1; i <= n; ++i)//查找度最大的结点
    {
        if(degree[i] > maxDeg)
        {
            maxDeg = degree[i];
            maxNum = i;
        }
    }
    cout<<maxNum<<endl;
    for(int i = 1; i <= n; ++i)//顺序遍历各个结点，看哪个结点是度最大结点的孩子
    {
        if(parent[i] == maxNum)
            cout<<i<<' ';
    }
    return 0;
}
