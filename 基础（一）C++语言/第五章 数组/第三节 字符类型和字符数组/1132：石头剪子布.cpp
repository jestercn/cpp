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
        else if (s1[0] == 'R' && s2[0] == 'S' ||//���ڱ�ʾʯͷ���Ӳ��������ַ���������ĸ������ͬ������ֻ�ж������ַ���������ĸ 
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
