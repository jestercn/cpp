#include<bits/stdc++.h>
using namespace std;
int n_max;
int nums[100001], p;//nums�����Ѿ���ֵ����� pָ�����ڿ��Ա������ֵ�λ��
int sum;
void Search(int n, int i_start)//�������n����ֳ���������СΪi_start, ÿ�ε���Search��ֳ�һ������
{
    for(int i = i_start; i <= n; ++i)
    {
        if(i == n_max)
            break;
        nums[p++] = i;
        sum += i;
        if(sum == n_max)
        {//����ӷ���ʽ
            cout<<n_max<<'='<<nums[0];
            for(int i = 1; i < p; ++i)
                cout<<'+'<<nums[i];
            cout<<endl;
            sum -= i;
            p--;
            break;
        }
        else if(sum < n_max)
        {
            Search(n-i, i);
            sum -= i;
            p--;
        }
        else
        {
            sum-=i;
            p--;
            break;
        }
    }
}

int main()
{
    cin>>n_max;
    Search(n_max, 1);
    return 0;
}
