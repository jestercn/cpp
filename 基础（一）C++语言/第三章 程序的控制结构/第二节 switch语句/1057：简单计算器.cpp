#include<bits/stdc++.h>
using namespace std; 
int main()
{
    int x, y;//声明两个整型变量，表示参与运算的数字
    char c;//声明字符型变量，表示运算符
    cin>>x>>y>>c;//输入变量
    switch(c)//switch选择语句，看变量c与哪个case后面的常量相等
    {
        case '+':
            cout<<x + y;
            break;
        case '-':
            cout<<x - y;
            break;
        case '*':
            cout<<x * y;
            break;
        case '/':
            if (y == 0)//如果除数是0
                cout<<"Divided by zero!";//输出：除0，这是非法运算
            else
                cout<<x / y;
            break;
        default:
            cout<<"Invalid operator!";
    }
    return 0;
}
