#include<bits/stdc++.h>
using namespace std; 
int main()
{
    int x, y;//�����������ͱ�������ʾ�������������
    char c;//�����ַ��ͱ�������ʾ�����
    cin>>x>>y>>c;//�������
    switch(c)//switchѡ����䣬������c���ĸ�case����ĳ������
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
            if (y == 0)//���������0
                cout<<"Divided by zero!";//�������0�����ǷǷ�����
            else
                cout<<x / y;
            break;
        default:
            cout<<"Invalid operator!";
    }
    return 0;
}
