#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h;
    cin>>h;
    double sum = h;//��һ������أ���������h 
    for(int i = 2; i <= 10; ++i)//i��ʾ�ڼ������ 
    {
        h /= 2;//h��ʾ�����غ���ĸ߶� 
        sum += 2 * h;//ÿ����ӵ�����أ���������2h 
    }
    cout<<sum<<endl<<h/2<<endl;
    return 0;
}
