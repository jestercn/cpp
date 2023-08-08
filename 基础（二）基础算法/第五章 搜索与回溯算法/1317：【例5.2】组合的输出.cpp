#include<bits/stdc++.h>
using namespace std;
bool used[22];//记录哪些数已经用过
int nums[22];//记录要输出哪些数，记录在num[1],num[2]...,num[r]
int n, r;//从n个元素中抽出r个元素
void Search(int p, int i_start)//p:查找排列中的第几个数, i_start这次搜索 从几开始
{
    for(int i = i_start; i <= n; ++i)
    {
        if(used[i] == false)//p为1时，取到num[0]，其值为0，已知i都大于0，不影响运行
        {
            nums[p] = i;
            used[i] = true;
            if(p == r)
            {//输出存在num中的排列数
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
bool used[22];//记录哪些数已经用过
int nums[22];//记录要输出哪些数，记录在num[1],num[2]...,num[r]
int n, r;//从n个元素中抽出r个元素
void Search(int p)//p:查找排列中的第几个数
{
    for(int i = 1; i <= n; ++i)
    {
        if(used[i] == false && i > nums[p-1])//p为1时，取到num[0]，其值为0，已知i都大于0，不影响运行
        {
            nums[p] = i;
            used[i] = true;
            if(p == r)
            {//输出存在num中的排列数
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
