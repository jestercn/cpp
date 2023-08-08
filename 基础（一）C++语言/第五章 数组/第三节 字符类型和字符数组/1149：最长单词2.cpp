#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[505], word[505], mxWord[505];
	cin.get(s, 505);
	int ct = 0, ctMax = 0, wi = 0;//ct:单词中字母计数 ctMax:最大单词长度 word_sp:最长单词开始的位置 
	for(int i = 0;i < strlen(s); ++i)
	{
		if(s[i] == ' ' || s[i] == '.')
		{
			word[wi] = '\0';
			wi = 0;
			if(ct > ctMax)
			{
				ctMax = ct;
				strcpy(mxWord, word);
			}
			ct = 0;
		}
		else
		{
			ct++;
			word[wi++] = s[i];
		}
	}
	cout<<mxWord;
	return 0;
}
