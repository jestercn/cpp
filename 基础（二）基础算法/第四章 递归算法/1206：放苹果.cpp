#include <bits/stdc++.h>
using namespace std;
//本问题等价于整数拆分问题，且拆分成的数字有限
//将一个整数M拆分为n个数相加的形式(n <= N)，问有多少种拆分方式。 （3 = 1 + 2 与 3 = 2 + 1是一种拆分）

//因而在实现时，要求拆分出的数字优秀
int numCount;//记录已经拆分了多少数字
int methodNum;//拆分方式数量
int M, N;

//对整数a进行一次拆分,  要求拆分出的数字>=minNum
void sepNum(int a, int minNum)
{
    if(a == 0)
        methodNum++;
    else
    {
        if(numCount < N)//如果拆出的数字数量小于N，可以进行拆分。
        {
            for(int i = minNum; i <= a; ++i)//本次拆分，拆分出数字i
            {
                numCount++;
                sepNum(a - i, i);
                numCount--;
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i)
    {
        cin>>M>>N;
        methodNum = 0;
        sepNum(M, 1);//对整数M进行一次拆分,  要求拆分出的最小数字是1
        cout<<methodNum<<endl;
    }
    return 0;
}
