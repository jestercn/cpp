#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[105];
    cin.get(s, 105);
    for(int i = 0; i < strlen(s); ++i)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] += 'A' - 'a';
    }
    cout<<s;
    return 0;
}
