#include <bits/stdc++.h>
using namespace std;
bool visited[10005];//满足对所有4位数的计数
int que[50000], head, tail;

//数字数组，转化为数字，如{0,2,1}转化为120
//arr：数字数组 arr[0]保存低位，arr[4]保存高位， n：数组长度 
int toNum(int arr[], int n)
{
    int pow = 1, s = 0; 
    for(int i = 0; i < n; ++i)
    {
        s += arr[i]*pow;
        pow *= 10;
    }
    return s;
}
int main()
{
    int n, k, x[20], y[20], num, d, count = 0;
    cin>>n>>k;
    for(int i = 0; i < k; ++i)//输入变换规则 
        cin>>x[i]>>y[i];
    que[++tail] = n;//数字入队 
    while(head!=tail)//直到队空 
    {
        num = que[++head];//数字出队 
        if(visited[num] == false)
        {
            visited[num] = true;
            count++;
            int numArr[5], na_i = 0;//保存各位数 从numArr[0]保存低位，numArr[4]保存高位 由于n小于等于2000，所以最有4个位置即可 
            for(int a = num; a > 0; a /= 10)
            {
                numArr[na_i++] = a % 10;//某一位数 保存 
            }
            for(int i = 0; i < na_i; ++i)//对于从低位到高位每位数字 
            {
                for(int j = 0; j < k; ++j)//j遍历k条变换规则 
                {
                    if(numArr[i] == x[j])//根据规则变换数字 
                    {
                        numArr[i] = y[j];//把numArr变为变换后的数字 
                        que[++tail] = toNum(numArr, na_i);//将numArr组合成新数字，入队 
                        numArr[i] = x[j];//numArr复原 
                    }  
                }
            }
        }
    }
    cout<<count; 
	return 0;
}
