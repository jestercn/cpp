#include <bits/stdc++.h>
using namespace std;
//散列存储
int main()
{
	char s[1005], maxCh;//maxCh：最大字母 
	int c[26]={}, maxNum = 0;//记录每个英文字符的个数 maxNum：字母最大数量 
	cin>>s;
	for(int i = 0; i < strlen(s); ++i) 
	{
		c[s[i] - 'a']++;
	}
	for(int i = 0;i < 26; ++i)
	{
		if(c[i] > maxNum)
		{
			maxCh = i + 'a';
			maxNum = c[i];
		}
	}
	cout<<maxCh<<' '<<maxNum;
	return 0;
} 
