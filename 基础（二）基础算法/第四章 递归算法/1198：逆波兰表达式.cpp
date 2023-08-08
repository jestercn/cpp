#include <bits/stdc++.h>
using namespace std;

//判断某一字符串是否是运算符
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

//解决一个逆波兰表达式 参数cal：运算符
double solve(char cal)
{
    double a, b;
    char s[100];
    cin>>s;
    if(isCal(s))//如果读入的是运算符，解决该运算符起始的一个逆波兰表达式
        a = solve(s[0]);
    else
        a = atof(s);//如果不是运算符，那么将其转为浮点数

    cin>>s;
    if(isCal(s))//如果读入的是运算符，解决该运算符起始的一个逆波兰表达式
        b = solve(s[0]);
    else
        b = atof(s);//如果不是运算符，那么将其转为浮点数

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
    //逆波兰表达式第一个字符一定是运算符
    char firstCal;
    scanf("%c", &firstCal);
    printf("%f\n", solve(firstCal));
    return 0;
}
