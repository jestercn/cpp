#include <bits/stdc++.h>
using namespace std;
//高精度加法
void Add(int a[], int b[], int r[])
{
    int c = 0, i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        r[i] = a[i] + b[i] + c;
        c = r[i] / 10;
        r[i] %= 10;
    }
    r[i] = c;
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

int main()
{
    int a[1000]={}, b[1000]={}, r[1000]={};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    cin>>s;
    toNumArr(s, b);
    Add(a, b, r);
    showNum(r);
}
