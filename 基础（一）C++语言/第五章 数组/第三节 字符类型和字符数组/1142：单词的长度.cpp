#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[1005];
	cin.get(s, 1005);
	//�ַ���ĩβ��һ���ո񣬱��ڼ���
	s[strlen(s) + 1] = '\0';
	s[strlen(s)] = ' '; 
	int ct = 0;//��ĸ����
	bool isFirst = true; 
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == ' ')
		{
			if(ct != 0)//ct == 0ʱ��Ϊ���������Ŀո� 
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
