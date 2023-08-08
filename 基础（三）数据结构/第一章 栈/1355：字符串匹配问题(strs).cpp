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

//获取左括号对应的数字 
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
//判断两个左括号字符哪一个更“小”，若c1比c2小，返回true，若c1比c2大，返回false
//括号从小到大：< ( [ { 
bool isSmaller(char c1, char c2)
{
	return getBracketNum(c1) < getBracketNum(c2);
}

//判断字符c是不是左括号 
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

//bl，br这对括号是否配对 bl是左括号 br是右括号 
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
//字符串s中的括号是否匹配 
bool isAllBrackMatch(char s[])
{
	for(int i = 0; i < strlen(s); ++i)
	{
		if(isLeft(s[i]))//如果是左括号 
		{
			if(stk_isEmpty()) 
				stk_push(s[i]);	
			else
			{
				if(isSmaller(s[i], stk_top()) || s[i] == stk_top())//如果要入栈的括号，比栈顶的括号更小，或一样，则入栈 
					stk_push(s[i]);
				else//否则括号不匹配 
					return false;
			}
		}
		else//如果是右括号 
		{
			if(isMatch(stk_top(), s[i]))//如果括号配对 
			{
				stk_pop();//将左括号出栈 
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
		stk_clear();//每次运行后不要忘了将栈清空 
	}
}
