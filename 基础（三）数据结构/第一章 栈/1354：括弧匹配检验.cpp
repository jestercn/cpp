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
            stk[++p] = s[i];//Ñ¹Õ»
        else
        {
            char c = stk[p--];//³öÕ»
            if(!(s[i] == ')' && c == '(' ||  s[i] == ']' && c == '[' ))//Èç¹ûÎ´Åä¶Ô
            {
                cout<<"Wrong";
                return 0;
            }
        }
    }
    if(p == 0)//Õ»¿Õ
        cout<<"OK";
    else
        cout<<"Wrong";
}
