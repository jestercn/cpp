#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        if (i % 7 == 0)//�����7�ı�������ô��7�й�
            continue;//��7�йأ���ô���¿�ʼѭ��������һ����i
        int m = i;
        bool isRelevant = false;//��־λ ��ʾ�Ƿ���7�й�
        while(m > 0)//ȡ���ֵĸ�����λ
        {
            if (m % 10 == 7)
            {
                isRelevant = true;
                break;
            }
            m /= 10;
        }
        if (isRelevant)//�����أ���ô����һ����
            continue;
        sum += i * i;//����޹أ���i*i�ӵ�sum��
    }
    cout<<sum<<endl;
    return 0;
}

/*
bool isRel7(int n)//�ú���ʵ�֣��ж�һ�����Ƿ���7�й�
{
    if(n%7 == 0)
        return true;
    int a = n;
    while(a>0)
    {
        int d = a % 10;
        if(d == 7)
            return true;
        a /= 10;
    }
    return false;
}

int main()
{
    int n, s = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        if(isRel7(i) == false)
            s += i * i;
    }
    cout<<s;
    return 0;
}
*/
