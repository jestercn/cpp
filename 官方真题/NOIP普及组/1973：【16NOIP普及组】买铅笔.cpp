#include<bits/stdc++.h>
using namespace std;
//ֻ��һ�ְ�װ
//��һ�ְ�װ�ĵ���Ϊx���ʵ�����Ϊy���������ֱ�m������֪��Ҫ�ܱ���Ϊn��
//��y * m >= n  ��  m >= n / y�� ��֪m����СֵΪ n/y����ȡ������ceil(n/y)
//���ٻ�Ǯ��Ϊceil(n/y) * x
//�Ƚ����ַ��������ٻ�Ǯ���������ٵĻ�Ǯ�������

int main()
{
    int n, x[3], y[3], m[3], mi = INT_MAX;//mi:���ٻ�Ǯ
    cin>>n;
    for(int i = 0; i < 3; ++i)//y��ʾ�ʵ�������x��ʾ�ʵĵ���
        cin>>y[i]>>x[i];
    for(int i = 0; i < 3; ++i)
    {
        int m = ceil(double(n) / y[i]) * x[i];
        if(m < mi)
            mi = m;
    }
    cout<<mi<<endl;
    return 0;
}
