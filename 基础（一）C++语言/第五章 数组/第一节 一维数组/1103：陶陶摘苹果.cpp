#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[15], h, c=0;
    for(int i = 0; i < 10; ++i)
        cin>>a[i];
    cin>>h;
    for(int i = 0; i < 10; ++i)
    {
        if(h+30 >= a[i])//�˸߼��ϵ��Ӹߣ�Ҫ�߹�ƻ���߶ȣ�����ժ�� 
            c++;
    }
    cout<<c;
    return 0;
}
