#include <bits/stdc++.h>
using namespace std;

//��Ŀ�Ѿ���֤������ַ������ǹؼ��֣���ôֻ��Ҫ�жϺ����� 
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
		   s[i] == '_'))//������ֲ�����Ҫ����ַ� 
		{
			cout<<"no";
			return 0;   	
		}
	}
	cout<<"yes";
    return 0;
}
