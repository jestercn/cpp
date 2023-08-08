#include <bits/stdc++.h>
using namespace std;
//�ж�num�Ƿ������� 
bool isPrime(int num)
{
    if(num < 2)
        return false;
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

//�ж�num�Ƿ��ǻ�����
bool isPal(int num)
{
    int s[6], i = 0;
    int a = num;
    while(a > 0)
    {
        s[i++] = a % 10;
        a /= 10;
    }
    //��ʱ i��ֵ��num��λ��
    for(int j = 0; j < i/2; ++j)
    {
        if(s[j] != s[i-1-j])
            return false;
    }
    return true;
}

int main()
{
    int n, s = 0;
    cin>>n;
    for(int i = 11; i <= n; ++i)
    {
        if(isPrime(i) && isPal(i))
            s++;
    }
    cout<<s;
    return 0;
}
