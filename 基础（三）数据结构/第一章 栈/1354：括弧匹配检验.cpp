#include<bits/stdc++.h>
using namespace std;
char stk[300];
int p;
int main()
{
    char s[300];
    cin>>s;
    for(int i = 0; i < strlen(s); ++i)
    {
        if(s[i] == '(' || s[i] == '[')
            stk[++p] = s[i];//ѹջ
        else
        {
            char c = stk[p--];//��ջ
            if(!(s[i] == ')' && c == '(' ||  s[i] == ']' && c == '[' ))//���δ���
            {
                cout<<"Wrong";
                return 0;
            }
        }
    }
    if(p == 0)//ջ��
        cout<<"OK";
    else
        cout<<"Wrong";
}
