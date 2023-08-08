#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int k, cn = 1;
    cin>>k;
    char s[2505];
    cin>>s;
    if(k == 1)
    {
        cout<<s[0];
        return 0;
    }
 
    for(int i = 1; i < strlen(s); ++i)
    {
        if(s[i] == s[i-1])
        {
            cn++;
            if(cn >= k)
            {
                cout<<s[i];
                return 0;
            }
        }
        else
        {
            cn = 1;
        }
    }
    cout<<"No";
}
