#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int c = 0;//�������Ƴ��ֹ����ٴ�1
    for(int i = 1; i<=n; ++i)
    {
        for(int a = i; a > 0; a /= 10)
        {
            if(a % 10 == 1)
                c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
/*
int count1(int num)//�ú�������һ��������1�ĸ���
{
    int c = 0;
    while(num>0)
    {
        int d = num%10;
        if(d == 1)
            c++;
        num /= 10;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int c = 0;
    for(int i = 1; i<=n; ++i)
    {
        c+=count1(i);
    }
    cout<<c<<endl;
    return 0;
}
*/
