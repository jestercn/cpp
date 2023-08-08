#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[105];
    cin>>s;
    for(int i=0, j=strlen(s) - 1; i<strlen(s) && j>=0; ++i,--j)
    {
        if(s[i] != s[j])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
}
