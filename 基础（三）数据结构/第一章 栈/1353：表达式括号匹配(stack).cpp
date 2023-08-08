#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[300];
    stack<char> stk;
    cin>>s;
    for(int i = 0; s[i]!='@'; ++i)
    {
        if(s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if(s[i] == ')')
        {
            bool isPair = false;//是否成功配对
            char c;
            while(stk.empty() == false)
            {
                c = stk.top();
                stk.pop();
                if(c == '(')//不断出栈直到找到一个左括号
                {
                    isPair = true;
                    break;
                }
            }
            if(isPair == false)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    //最后如果栈空，那么配对成功，否则配对失败
    if(stk.empty())
        cout<<"YES";
    else
        cout<<"NO";
}
