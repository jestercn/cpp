#include<bits/stdc++.h>
using namespace std;
//��arctan(x),С��1e6������ӽ�ȥ 
double arctan(double x)
{
    double sum = 0, temp = x;
    for(int i = 1; fabs(temp / i) >= 1e-6; i += 2)//���һ�����ֵ���ڵ���10^(-6)ʱ����ѭ��
    {
        sum += temp / i;//�ۼӸ���
        temp = - x * x * temp;//����һ��
    }
    return sum;
} 
int main()
{
    cout<<fixed<<setprecision(10)<<6*arctan(1/sqrt(3)); 
    return 0;
}

