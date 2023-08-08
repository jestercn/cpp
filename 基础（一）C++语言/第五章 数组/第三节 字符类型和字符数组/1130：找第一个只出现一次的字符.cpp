#include <bits/stdc++.h>
using namespace std;
//考察散列存储思想 
int main()
{
    int a[26] = {};//数组a第0~第25元素分别保存'a'出现的次数，'b'出现的次数...'z'出现的次数
	char s[100005];
	scanf("%s", s);
	int len = strlen(s);//strlen有O(n)的复杂度，若字符串很长时，减少调用strlen的次数有助于减少运行时间 
	for(int i = 0; i < len; ++i)
	{
		a[s[i] - 'a']++;
	}
	for(int i = 0; i < len; ++i)//遍历字符串，找到第一个只出现一次的字符 
	{
		if(a[s[i]-'a'] == 1)
		{
			printf("%c", s[i]);
			return 0;
		}
	}
	printf("no");//没找到 
    return 0;
}
