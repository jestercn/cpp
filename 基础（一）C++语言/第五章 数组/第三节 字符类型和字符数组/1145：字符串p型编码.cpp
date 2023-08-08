#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[1005], curNum;
	cin>>s;
	int ct = 0; 
	curNum = s[0];
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == curNum)
		{
			ct++;
		}
		else
		{
			cout<<ct<<curNum;
			curNum = s[i];
			ct = 1;
		}
	}
	cout<<ct<<curNum;
}
