#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[50],c3,c2,c1;//c3~c1是倒数第3，2,1个字符 
    cin>>s;
    int len = strlen(s);
    c1 = s[len-1];
    c2 = s[len-2];
    c3 = s[len-3];
    if(c3 == 'i' && c2 == 'n' && c1 == 'g')
        s[len-3] = '\0';
    else if(c2 == 'e' && c1 == 'r' || c2 == 'l' && c1 == 'y')
        s[len-2] = '\0';
    cout<<s;
} 
