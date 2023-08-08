#include <bits/stdc++.h>
using namespace std;

//题目已经保证输入的字符串不是关键字，那么只需要判断后两条 
int main()
{
	char s[25];
   	cin>>s;
   	if(s[0] >= '0' && s[0] <= '9')
   	{
   		cout<<"no";
   		return 0;
	}
   	for(int i = 0; i < strlen(s); ++i)
   	{
   		if(!(s[i] >= '0' && s[i] <= '9' || 
		   s[i] >= 'a' && s[i] <= 'z' ||
		   s[i] >= 'A' && s[i] <= 'Z' ||
		   s[i] == '_'))//如果出现不满足要求的字符 
		{
			cout<<"no";
			return 0;   	
		}
	}
	cout<<"yes";
    return 0;
}
