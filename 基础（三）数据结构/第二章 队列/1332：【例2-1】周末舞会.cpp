#include <bits/stdc++.h>
using namespace std;
//������������
int que_m[1000], que_f[1000];
int h_m, t_m, h_f, t_f;//�������е�ͷβָ��

int main()
{
    int m, f, temp_m, temp_f, n;//m,f:��Ů���� temp_m, temp_f:��ʱ���ӵ���Ů��� n:������
    cin>>m>>f>>n;
    for(int i = 1; i <= m; ++i)//��ʿ���
        que_m[++t_m] = i;
    for(int i = 1; i <= f; ++i)//Ůʿ���
        que_f[++t_f] = i;
    for(int i = 0; i < n; ++i)
    {
        temp_m = que_m[++h_m];//�жӣ�Ů�Ӹ�����1��
        temp_f = que_f[++h_f];
        cout<<temp_m<<' '<<temp_f<<endl;
        que_m[++t_m] = temp_m;//���������ӵ��������
        que_f[++t_f] = temp_f;
    }
	return 0;
}
