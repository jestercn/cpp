#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n < 0)//���������С��0����ô������ţ����������ֱ�Ϊ����
    {
        cout<<'-';
        n = -n;
    }
    bool isPreZero = true;//��־λ�������Ƿ������ǰ���0��״̬
    while(n > 0)
    {
        int d = n%10;
        n /= 10;
        if(isPreZero)//�����������ǰ���0��״̬
        {
            if(d == 0)//����һ����Ϊ0
                continue;//��ô����������¿�ʼѭ��
            else
                isPreZero = false;//�������ǰ���0��״̬����
        }
        cout<<d;
    }
    return 0;
}
