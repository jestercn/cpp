#include <bits/stdc++.h>
using namespace std;
//ɢ�д洢
int main()
{
	char s[1005], maxCh;//maxCh�������ĸ 
	int c[26]={}, maxNum = 0;//��¼ÿ��Ӣ���ַ��ĸ��� maxNum����ĸ������� 
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
