#include <bits/stdc++.h>
using namespace std;
long long stk[280];
int p;
void push(long long a)
{
	stk[++p] = a;
}

long long pop()
{
	return stk[p--];
}

long long calc(long long a, long long b, char c)//����a��b�������c��������ֵ 
{
	switch(c)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		default:;
	}
}

int main()
{
	char s[260];//���������ַ��� 
	long long num = 0;//����ֽ���������� 
	cin.get(s, 260);
	for(int i = 0; s[i]!='@'; ++i)//�����ַ��� 
	{
		if(s[i]>='0' && s[i]<='9')//����������ַ�����������num 
		{
			num = num * 10 + (s[i] - '0');
		}
		else if(s[i] == ' ')//��������ո��������num�Ĺ��죬��numѹջ 
		{
			push(num);
			num = 0;
		}
		else//���������������ջ�����������м��� 
		{
			long long b = pop();
			long long a = pop();
			long long res = calc(a, b, s[i]);
			push(res);
		}
	}
	cout<<pop();//���ջ��ʣ�µ����֣��������Ľ������ջ���������	
	return 0;
}

