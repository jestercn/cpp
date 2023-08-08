#include<bits/stdc++.h>
using namespace std;
int n_max;
int nums[100001], p;//nums保存已经拆分的数字 p指向现在可以保存数字的位置
int sum;
void Search(int n, int i_start)//拆分数字n，拆分出的数字最小为i_start, 每次调用Search拆分出一个数字
{
    for(int i = i_start; i <= n; ++i)
    {
        if(i == n_max)
            break;
        nums[p++] = i;
        sum += i;
        if(sum == n_max)
        {//输出加法公式
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
