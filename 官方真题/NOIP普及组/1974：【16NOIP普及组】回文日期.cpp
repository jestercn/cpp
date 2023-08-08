#include<bits/stdc++.h>
using namespace std;
//���㣺
//ģ�⣺��������
//���죺�ַ����飬���ֲ�֣��жϻ����ַ���, �ж��Ƿ�������

typedef struct Date//���ڽṹ��
{
    int y, m, d;//������
    int md;//��ǰ�·�����
    Date(char s[])//���ַ�����ʼ������
    {
        int n[10];
        for(int i = 0; i < 8; ++i)//��תΪ��������
            n[i] = s[i] - '0';
        y = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
        m = n[4] * 10 + n[5];
        d = n[6] * 10 + n[7];
        setMonthDayNum();
    }
    //�жϵ����Ƿ�������
    bool isLeapYear()
    {
        return y % 400 == 0 || y % 100 != 0 && y % 4 == 0;
    }
    bool operator <= (Date b)//����������b����
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
    void operator ++ ()//���ڼ�1���������Ϊǰ��++
    {
        d++;
        if(d > md)//����ճ�������������
        {
            d = 1;//����Ϊ1
            m++;//�·ݼ�1
            if(m > 12)//����·ݳ���12
            {
                y++;
                m = 1;
            }
            setMonthDayNum();//�������·ݵ�����
        }
    }
    void setMonthDayNum()//���õ�������
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
                if(isLeapYear())//�����ǰ��������
                    md = 29;
                else
                    md = 28;
                return;
        }
    }
    bool isHuiwen()//����������еĸ�λ���γ���������
    {
        int a[10], i = 3;
        for(int n = y; n > 0; n /= 10)
            a[i--] = n % 10;
        a[4] = m / 10;
        a[5] = m % 10;
        a[6] = d / 10;
        a[7] = d % 10;
        for(int i = 0; i < 4; ++i)//�ж��Ƿ����
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
    int ct = 0;//ct:����
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
