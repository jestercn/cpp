#include <bits/stdc++.h>
using namespace std;
//高精度减法

//高精度减法函数，两数满足a>=b，a，b都是数字数组，r保存结果
void Minus(int a[], int b[], int r[])
{
    int i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        if(a[i] < b[i])
        {
            a[i+1]--;
            a[i] += 10;
        }
        r[i] = a[i] - b[i];
    }
    while(r[i] == 0 && i > 1)//去除多余的0
        i--;
    r[0] = i;
}

//将字符数组转化为数字数组 数字数组从第1位置到第len位置，从低位到高位保存各位数字，第0位置保存数字位数
void toNumArr(char s[], int a[])
{
    int len = strlen(s);
    a[0] = len;
    for(int i = 0; i < len; ++i)
    {
        a[i + 1] = s[len - 1 - i] - '0';
    }
}

void showNum(int a[])
{
    for(int i = a[0]; i >= 1; --i)
        cout<<a[i];
    cout<<endl;
}
//比较两个数字数组 如果a比b大，返回1，如果a比b小，返回-1，如果二者相等，返回0
int compare(int a[], int b[])
{
    if(a[0] > b[0])//如果a的位数比较多
        return 1;
    else if (a[0] < b[0])//如果b的位数比较多
        return -1;
    else
    {
        for(int i = a[0]; i >= 1; --i)
        {
            if(a[i] > b[i])
                return 1;
            else if(a[i] < b[i])
                return -1;
        }
        return 0;
    }
}

int main()
{
    int a[1000]={}, b[1000]={}, r[1000]={};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    cin>>s;
    toNumArr(s, b);
    if(compare(a, b) < 0)
    {
        cout<<'-';
        Minus(b, a, r);
    }
    else
        Minus(a, b, r);
    showNum(r);
}
