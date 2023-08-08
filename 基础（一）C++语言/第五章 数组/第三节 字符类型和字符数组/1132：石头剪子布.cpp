#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        char s1[10], s2[10];
        cin>>s1>>s2;
        if(strcmp(s1, s2) == 0)
            cout<<"Tie"<<endl;
        else if (s1[0] == 'R' && s2[0] == 'S' ||//由于表示石头剪子布的三个字符串的首字母都不相同，这里只判断两个字符串的首字母 
                s1[0] == 'S' && s2[0] == 'P' ||
                s1[0] == 'P' && s2[0] == 'R')
                cout<<"Player1"<<endl;
        else if (s1[0] == 'S' && s2[0] == 'R' ||
                s1[0] == 'P' && s2[0] == 'S' ||
                s1[0] == 'R' && s2[0] == 'P')
                cout<<"Player2"<<endl;
    }
    return 0;
}
