#include<bits/stdc++.h>
using namespace std;
//˳ʱ����ת90�ȣ�������ת�����棬����ת�����棬����ת�����棬����ת������
//����һ�б�����һ�У��ڶ��б�ɵ����ڶ��С��������һ�б�ɵ�һ��  
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
        	b[j][n - 1 - i] = a[i][j];//ת������к���ԭ�����кţ�ת������к���ԭ�����������ȥ�к� 
        }
        
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout<<b[i][j]<<' ';
        cout<<endl;
    }
}
 
