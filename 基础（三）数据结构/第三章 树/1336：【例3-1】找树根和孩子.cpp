#include <bits/stdc++.h>
using namespace std;

int main()
{
    int parent[101] = {}, degree[101] = {};//parent[i] ��ʾ���i��˫��, degree[i]��ʾ���i�Ķ�
    int n, m, x, y, root, maxDeg = 0, maxNum = 1;//root:��ʾ������ţ�maxNum:����߽���ţ�maxDeg����ʾ����߽��Ķȣ������ӶԶ�Ľ��ĺ�����
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
        degree[parent[i]]++;//���i��˫�׵Ķȼ�1
    }
    cout<<root<<endl;
    for(int i = 1; i <= n; ++i)//���Ҷ����Ľ��
    {
        if(degree[i] > maxDeg)
        {
            maxDeg = degree[i];
            maxNum = i;
        }
    }
    cout<<maxNum<<endl;
    for(int i = 1; i <= n; ++i)//˳�����������㣬���ĸ�����Ƕ������ĺ���
    {
        if(parent[i] == maxNum)
            cout<<i<<' ';
    }
    return 0;
}
