#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[85];
    gets(s);
    for(int i = 0; i < strlen(s); ++i)
    {
        if(s[i] >= 'a' && s[i] <= 'y' || s[i] >= 'A' && s[i] <= 'Y' )
            s[i]++;
        else if (s[i] == 'z' || s[i] == 'Z')
            s[i] -= 25;
    }
    puts(s);
}
