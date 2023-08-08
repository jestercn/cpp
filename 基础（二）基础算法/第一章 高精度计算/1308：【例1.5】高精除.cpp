#include <bits/stdc++.h>
using namespace std;
//高精度除以高精度 
//比较两个数字数组 如果a比b大，返回1，如果a比b小，返回-1，如果二者相等，返回0
int numcmp(int a[], int b[])
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

//将数字数组b复制到数字数组a之中
void numcpy(int a[], int b[])
{
    for(int i = 0; i <= b[0]; ++i)
        a[i] = b[i];
}

//高精度减法函数
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

//高精度除法中的减法代替除法操作，实际就是除法的另一种实现方式
//a是被除数 b是除数
//返回值为商，计算后数组a保存的是余数
int minusInDivide(int a[], int b[])
{
    int minusTimes = 0;//minusTimes：减的次数
    int r[1000] = {};
    while(true)
    {
        if(numcmp(a, b) < 0)
        {
            return minusTimes;
        }
        else
        {
            Minus(a, b, r);
            numcpy(a, r);//将a设为上次减法的结果
            minusTimes++;
        }
    }
}

//在数字数组的个位添加一位数，0 <= num <= 9
void addNum(int a[], int num)
{
    for(int i = a[0]; i >= 1; --i)//数组移位
    {
        a[i+1] = a[i];
    }
    a[1] = num;
    a[0]++;
}

//高精度数字除以高精度数字
void Divide(int a[], int b[], int r[])
{
    int x[1000] = {};//x:中间临时使用的数字，是上一次不断减数后余下的数，以及作为下一次的被减数
    for(int i = a[0]; i >= 1; --i)
    {
        addNum(x, a[i]);
        r[i] = minusInDivide(x, b);
    }
    int r_i = a[0];//删除多余的0
    while(r[r_i] == 0 && r_i > 1)
        r_i--;
    r[0] = r_i;
}

//高精度数字对高精度数字取模
void Mod(int a[], int b[], int x[])
{
    for(int i = a[0]; i >= 1; --i)
    {
        addNum(x, a[i]);
        minusInDivide(x, b);
    }
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
    int a[1000] = {}, b[1000] = {}, r[1000] = {}, x[1000] = {};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    cin>>s;
    toNumArr(s, b);
    Divide(a, b, r);
    Mod(a, b, x);
    showNum(r);
    showNum(x);
}
