#include <bits/stdc++.h>
using namespace std;

int methodCount;//�ߵķ�����

//��n��̨��
void walk(int n)
{
    if(n == 0)//���û�п��ߵ�̨�ף�˵��n��̨�������ˣ��߷���һ
        methodCount++;
    else
    {
        if(n >= 2)
            walk(n - 2);//������
        if(n >= 1)
            walk(n - 1);//��һ��
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        methodCount = 0;
        walk(n);
        cout<<methodCount<<endl;
    }
    return 0;
}
