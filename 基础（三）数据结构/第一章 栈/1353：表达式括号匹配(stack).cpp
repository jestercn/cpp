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
            bool isPair = false;//�Ƿ�ɹ����
            char c;
            while(stk.empty() == false)
            {
                c = stk.top();
                stk.pop();
                if(c == '(')//���ϳ�ջֱ���ҵ�һ��������
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
    //������ջ�գ���ô��Գɹ����������ʧ��
    if(stk.empty())
        cout<<"YES";
    else
        cout<<"NO";
}
