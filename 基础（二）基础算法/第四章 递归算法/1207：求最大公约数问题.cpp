#include <bits/stdc++.h>
using namespace std;

//շת����������Լ��
//��gcd(a, b)
//��b == 0ʱ��a��Ϊ�����������Լ��
//������gcd(b, a%b)
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);//β�ݹ�
}

int main()
{
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b);
    return 0;
}
