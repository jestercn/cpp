#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[505];
    gets(s);
    char word[500];
    int k = 0;
    for(int i = 0; i < strlen(s); ++i)
    {
        if(s[i] != ' ')
        {
            word[k++] = s[i];
        }
        else
        {
            word[k] = '\0';
            for(int j = strlen(word) - 1; j >= 0; j--)
                cout<<word[j];
            cout<<' ';
            k = 0;
            word[k] = '\0';
        }
    }
    word[k] = '\0';
    for(int j = strlen(word) - 1; j >= 0; j--)
        cout<<word[j];
}
