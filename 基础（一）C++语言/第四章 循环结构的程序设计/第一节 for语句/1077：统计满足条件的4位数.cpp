#include<bits/stdc++.h>
using namespace std;
bool isOk(int n)//�Ƿ��������� 
{
    int d = n % 10;//ȡ��λ 
    n /= 10;
    while(n>0)
    {
        d -= n%10;//��λ��ֵ���ϼ�ȥ����λ��ֵ 
        n /= 10;
    }
    return d > 0;//��λ��ֵ��ȥ��������λ��ֵ���Ƿ����0 
}

int main()
{
   int n, s=0;
   cin>>n;
   for(int i = 0; i < n; ++i)
   {
        int a;
        cin>>a;
        if(isOk(a))
            s++;
   }
   cout<<s;
}
