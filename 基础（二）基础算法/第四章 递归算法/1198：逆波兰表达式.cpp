#include <bits/stdc++.h>
using namespace std;

//�ж�ĳһ�ַ����Ƿ��������
bool isCal(char s[])
{
    if(strlen(s) == 1)
    {
        if(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')
            return true;
        else
            return false;
    }
    else
        return false;
}

//���һ���沨�����ʽ ����cal�������
double solve(char cal)
{
    double a, b;
    char s[100];
    cin>>s;
    if(isCal(s))//�����������������������������ʼ��һ���沨�����ʽ
        a = solve(s[0]);
    else
        a = atof(s);//����������������ô����תΪ������

    cin>>s;
    if(isCal(s))//�����������������������������ʼ��һ���沨�����ʽ
        b = solve(s[0]);
    else
        b = atof(s);//����������������ô����תΪ������

    switch(cal)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}

int main()
{
    //�沨�����ʽ��һ���ַ�һ���������
    char firstCal;
    scanf("%c", &firstCal);
    printf("%f\n", solve(firstCal));
    return 0;
}
