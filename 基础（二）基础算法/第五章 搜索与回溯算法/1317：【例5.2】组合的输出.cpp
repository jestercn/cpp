#include<bits/stdc++.h>
using namespace std;
bool used[22];//��¼��Щ���Ѿ��ù�
int nums[22];//��¼Ҫ�����Щ������¼��num[1],num[2]...,num[r]
int n, r;//��n��Ԫ���г��r��Ԫ��
void Search(int p, int i_start)//p:���������еĵڼ�����, i_start������� �Ӽ���ʼ
{
    for(int i = i_start; i <= n; ++i)
    {
        if(used[i] == false)//pΪ1ʱ��ȡ��num[0]����ֵΪ0����֪i������0����Ӱ������
        {
            nums[p] = i;
            used[i] = true;
            if(p == r)
            {//�������num�е�������
                for(int j = 1; j <= r; ++j)
                    cout<<setw(3)<<nums[j];
                cout<<endl;
            }
            else
                Search(p+1, i+1);
            used[i] = false;
        }
    }
}

int main()
{
    cin>>n>>r;
    Search(1, 1);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
bool used[22];//��¼��Щ���Ѿ��ù�
int nums[22];//��¼Ҫ�����Щ������¼��num[1],num[2]...,num[r]
int n, r;//��n��Ԫ���г��r��Ԫ��
void Search(int p)//p:���������еĵڼ�����
{
    for(int i = 1; i <= n; ++i)
    {
        if(used[i] == false && i > nums[p-1])//pΪ1ʱ��ȡ��num[0]����ֵΪ0����֪i������0����Ӱ������
        {
            nums[p] = i;
            used[i] = true;
            if(p == r)
            {//�������num�е�������
                for(int j = 1; j <= r; ++j)
                    cout<<setw(3)<<nums[j];
                cout<<endl;
            }
            else
                Search(p+1);
            used[i] = false;
        }
    }
}

int main()
{
    cin>>n>>r;
    Search(1);
    return 0;
}
*/
