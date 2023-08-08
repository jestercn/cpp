#include<bits/stdc++.h>
using namespace std;
char s[1000005];
void lower(char s[], int len)
{
	for(int i = 0; i < len; ++i)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}

int main()
{
	char word[100], selWord[100];
	int k = 0, firstPos = -1, ct = 0;//k为word的下标，若当前遍历的单词已经与word不同，那么将k设为-1 
	cin>>word;
	cin.get();
	cin.get(s, 1000005);
	int len = strlen(s), lenw = strlen(word);
	s[len+1] = '\0';
	s[len] = ' ';
	lower(word, lenw);
	lower(s, len);
	for(int i = 0;i < len; ++i)
	{
		if(s[i] == ' ')
		{
			if(k == lenw)
			{
				ct++;
				if(firstPos == -1)
					firstPos = i - lenw;
			}
			k = 0;
		}
		else
		{
			if(k >= 0)
			{
				if(word[k] == s[i])
					k++;
				else
					k = -1;
			}
		}
	}
	if(firstPos == -1)
		cout<<-1;
	else
		cout<<ct<<' '<<firstPos;
    return 0;
}

