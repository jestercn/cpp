#include<bits/stdc++.h>
using namespace std;
//��1�׶Σ�����ÿ���1����ң���2�׶Σ�����ÿ���2����ң��Դ�����
int main()
{
    int n;
    cin>>n;
    int sum = 0, d = 1, j = 1;//d����ǰ�ڵڼ��׶�, j������һ�׶εڼ���
    for(int i = 1; i <= n; ++i)//i����ǰ���ڵڼ���
    {
        sum += d;
        if(j >= d) //����Ѿ��ﵽ��d�׶εĵ�d�죬��ô�ý�����һ�׶�
        {
            d++;
            j = 1;
        }
        else
            j++;
    }
    cout<<sum;
}
