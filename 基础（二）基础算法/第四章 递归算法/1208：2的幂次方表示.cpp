#include <bits/stdc++.h>
using namespace std;
//�����ư�λȨչ��

void showByTwo(int val)
{
    if(val == 0)
    {
        cout<<'0';
        return;
    }
    int m = 0, highVal = 1;//m��¼valת���ɵĶ���������λ��, highVal��¼��ߴ��ݵ�ֵ
    for(int a = val; a > 0; a /= 2)
        m++;
    for(int i = 0; i < m - 1; ++i)//չ������ߴ������ָ��Ϊm-1����ȡ��ߴ��ݵ�ֵ
        highVal *= 2;
    cout<<"2";
    if(m - 1 != 1)//���2��ָ�������ָ����1�������������1
    {
        cout<<'(';
        showByTwo(m - 1);
        cout<<')';
    }
    if(val > highVal)//�������ӵ�����
    {
        cout<<'+';
        showByTwo(val - highVal);//ԭֵ��ȥ��ߴ��ݵ�ֵ����ʣ�µ������ٽ��в��
    }
}

int main()
{
    int n;
    cin>>n;
    showByTwo(n);
    return 0;
}
