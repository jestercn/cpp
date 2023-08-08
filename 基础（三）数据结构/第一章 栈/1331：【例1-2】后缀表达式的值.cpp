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

long long calc(long long a, long long b, char c)//数字a，b和运算符c，运算后的值 
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
	char s[260];//读入整个字符串 
	long long num = 0;//保存分解出来的数字 
	cin.get(s, 260);
	for(int i = 0; s[i]!='@'; ++i)//遍历字符串 
	{
		if(s[i]>='0' && s[i]<='9')//如果是数字字符，则构造数字num 
		{
			num = num * 10 + (s[i] - '0');
		}
		else if(s[i] == ' ')//如果遇到空格，完成数字num的构造，将num压栈 
		{
			push(num);
			num = 0;
		}
		else//如遇到运算符，出栈两个数，进行计算 
		{
			long long b = pop();
			long long a = pop();
			long long res = calc(a, b, s[i]);
			push(res);
		}
	}
	cout<<pop();//最后栈中剩下的数字，就是最后的结果。出栈并输出它。	
	return 0;
}

