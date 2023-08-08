#include<bits/stdc++.h>
using namespace std;
char stk[260];
int p;
void stk_push(char c)
{
	stk[++p] = c;
}
char stk_pop()
{
	return stk[p--];
}
char stk_top()
{
	return stk[p];
}
bool stk_isEmpty()
{
	return p == 0;
}
void stk_clear()
{
	p = 0;
} 

//��ȡ�����Ŷ�Ӧ������ 
int getBracketNum(char c)
{
	switch(c)
	{
		case '<':
			return 1;
		case '(':
			return 2;
		case '[':
			return 3;
		case '{':
			return 4;
	}
}
//�ж������������ַ���һ������С������c1��c2С������true����c1��c2�󣬷���false
//���Ŵ�С����< ( [ { 
bool isSmaller(char c1, char c2)
{
	return getBracketNum(c1) < getBracketNum(c2);
}

//�ж��ַ�c�ǲ��������� 
bool isLeft(char c)
{
	switch(c)
	{
		case '<':
		case '(':
		case '[':
		case '{':
			return true;
		case '>':
		case ')':
		case ']':
		case '}':
			return false;
	}
}

//bl��br��������Ƿ���� bl�������� br�������� 
bool isMatch(char bl, char br)
{
	if(bl == '<' && br == '>' ||
		bl == '(' && br == ')' ||
		bl == '[' && br == ']' ||
		bl == '{' && br == '}')
		return true;
	else
		return false;
}
//�ַ���s�е������Ƿ�ƥ�� 
bool isAllBrackMatch(char s[])
{
	for(int i = 0; i < strlen(s); ++i)
	{
		if(isLeft(s[i]))//����������� 
		{
			if(stk_isEmpty()) 
				stk_push(s[i]);	
			else
			{
				if(isSmaller(s[i], stk_top()) || s[i] == stk_top())//���Ҫ��ջ�����ţ���ջ�������Ÿ�С����һ��������ջ 
					stk_push(s[i]);
				else//�������Ų�ƥ�� 
					return false;
			}
		}
		else//����������� 
		{
			if(isMatch(stk_top(), s[i]))//���������� 
			{
				stk_pop();//�������ų�ջ 
			}
			else
				return false;
		}
	}
	
	if(stk_isEmpty())
		return true;
	else
		return false;
}
int main()
{
	int n;
	char s[260];
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>s;
		if(isAllBrackMatch(s))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		stk_clear();//ÿ�����к�Ҫ���˽�ջ��� 
	}
}
