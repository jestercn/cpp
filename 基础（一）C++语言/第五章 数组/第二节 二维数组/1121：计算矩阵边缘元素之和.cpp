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
        sum += a[0][j];//�����1�еĺ� 
        if (0 != m-1)//������󲢷�ֻ��1�У��������һ�еĺ� 
            sum += a[m-1][j];
    }
    for(int i = 1; i < m-1; ++i)
    {
        sum += a[i][0];//�����1�г�����������Ԫ�أ��ĺ� 
        if (0 != n-1)//������󲢷�ֻ��1�У��������һ�г�����������Ԫ�صĺ� 
            sum += a[i][n-1];
    }
    cout<<sum;
    return 0;
}
