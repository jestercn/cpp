#include<bits/stdc++.h>
using namespace std;
char upper(char c)
{
    if(c >= 'a' && c <= 'z')
        return c + 'A' - 'a';
    else
        return c;
}
 
char lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}
void procWord(char s[])
{
    s[0] = upper(s[0]);
    for(int i = 1; i < strlen(s); ++i)
        s[i] = lower(s[i]);
}
 
int main()
{
    int n;
    char s[25];
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        cin>>s;
        procWord(s);
        cout<<s<<endl;
    }
} 
