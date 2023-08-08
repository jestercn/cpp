#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[1005];
	cin.get(s, 1005);
	//字符串末尾填一个空格，便于计算
	s[strlen(s) + 1] = '\0';
	s[strlen(s)] = ' '; 
	int ct = 0;//字母计数
	bool isFirst = true; 
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == ' ')
		{
			if(ct != 0)//ct == 0时，为出现连续的空格 
			{
				if(isFirst)
					isFirst = false;
				else
					cout<<',';
				cout<<ct;
				ct = 0; 
			}
		}
		else
		{
			ct++;
		}
	}
	return 0;
}
