#include<bits/stdc++.h>
using namespace std;
//考点：
//模拟：日期增加
//考察：字符数组，数字拆分，判断回文字符串, 判断是否是闰年

typedef struct Date//日期结构体
{
    int y, m, d;//年月日
    int md;//当前月份天数
    Date(char s[])//以字符串初始化日期
    {
        int n[10];
        for(int i = 0; i < 8; ++i)//先转为数字数组
            n[i] = s[i] - '0';
        y = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
        m = n[4] * 10 + n[5];
        d = n[6] * 10 + n[7];
        setMonthDayNum();
    }
    //判断当年是否是闰年
    bool isLeapYear()
    {
        return y % 400 == 0 || y % 100 != 0 && y % 4 == 0;
    }
    bool operator <= (Date b)//本日期早于b日期
    {
        if(y < b.y)
            return true;
        else if(y > b.y)
            return false;
        else
        {
            if(m < b.m)
                return true;
            else if (m > b.m)
                return false;
            else
            {
                if(d <= b.d)
                    return true;
                else
                    return false;
            }
        }
    }
    void operator ++ ()//日期加1，该运算符为前置++
    {
        d++;
        if(d > md)//如果日超出当月总天数
        {
            d = 1;//日设为1
            m++;//月份加1
            if(m > 12)//如果月份超出12
            {
                y++;
                m = 1;
            }
            setMonthDayNum();//设置新月份的天数
        }
    }
    void setMonthDayNum()//设置当月天数
    {
        switch(m)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                md = 31;
                return;
            case 4:case 6:case 9:case 11:
                md = 30;
                return;
            case 2:
                if(isLeapYear())//如果当前年是闰年
                    md = 29;
                else
                    md = 28;
                return;
        }
    }
    bool isHuiwen()//分离出日期中的各位，形成数字数组
    {
        int a[10], i = 3;
        for(int n = y; n > 0; n /= 10)
            a[i--] = n % 10;
        a[4] = m / 10;
        a[5] = m % 10;
        a[6] = d / 10;
        a[7] = d % 10;
        for(int i = 0; i < 4; ++i)//判断是否回文
        {
            if(a[i] != a[7-i])
                return false;
        }
        return true;
    }
}Date;

int main()
{
    char s1[10], s2[10];
    int ct = 0;//ct:计数
    cin>>s1>>s2;
    Date d1(s1), d2(s2);
    for(Date d = d1; d <= d2; ++d)
    {
        if(d.isHuiwen())
            ct++;
    }
    cout<<ct<<endl;
    return 0;
}
