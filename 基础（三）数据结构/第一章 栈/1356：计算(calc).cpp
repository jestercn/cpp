#include<bits/stdc++.h>
using namespace std;
/*思路:设一个数字栈，一个运算符栈。从左到右扫描算式字符串，读到数字字符，将几个数字字符整合为数字，而后将数字压入数字栈。
若读到运算符，将运算符有条件地压入运算符栈。运算符优先级:右括号 小于 加减 小于 乘除 小于 乘方 小于 左括号
若待压入的运算符的优先级，大于栈顶运算符的优先级，则压入。
若待压入的运算符的优先级，小于等于栈顶运算符的优先级，则进行多次“基本计算”，直到可以压栈。 
“基本计算”方法：取栈顶运算符c，数字栈出栈数字b，出栈数字a，求a，b经过c运算后的值，将这一值压入数字栈

若待压入的是右括号，此时运算符栈顶是左括号，那么运算符栈出栈
扫描字符串后，不断进行“基本计算”，运算符栈为空时，数字栈出栈的值就是最终结果 
*/

int getCalNum(char c)
{
	switch(c)
	{
		case ')':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		case '^':
			return 4;
		case '(':
			return 5;
	}	
}

//运算符c1是否比运算符c2优先级更高 
bool isSuperior(char c1, char c2)
{
	return getCalNum(c1) > getCalNum(c2);
}

//算数计算 
int calc(int a, int b, char c)
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
		case '^':
			return (int)pow(a,b);
	}	
}

int main()
{
	int n;
	char s[300];
	cin>>s;//假设输入的是合法的表达式 
	int len = strlen(s);
	s[len] = ')';//取巧，把一个优先级最低的符号')'加到字符串末尾，促使完成最后的计算。 
	int num = 0;
	stack<int> stk_num;//数字栈 
	stack<char> stk_cal;//运算符栈 
	bool isFormingNum = false;//标志位 表示是否正在构造数字 
	for(int i = 0; i <=len; ++i)
	{
		if(s[i] >= '0' && s[i] <= '9')//如果扫描到数字 
		{
			isFormingNum = true;
			num = num * 10 + s[i] - '0';//将字符串转化为数 
		}
		else//如果扫描到运算符 
		{
			if(isFormingNum)
			{
				stk_num.push(num);//将构造好的数字压入数字栈 
				num = 0;//保存数字的变量复原
				isFormingNum = false;
			}
			//若待压入的运算符的优先级，小于等于栈顶运算符的优先级，则进行多次“基本计算”，直到可以压栈，或遇到左括号 计算结束  
			while(!(stk_cal.empty() || isSuperior(s[i], stk_cal.top()) || stk_cal.top() == '('))
			{
				int b = stk_num.top();
				stk_num.pop();
				int a = stk_num.top();
				stk_num.pop();
				char c = stk_cal.top();
				stk_cal.pop();
				stk_num.push(calc(a, b, c));
			}
			if(stk_cal.empty() == false && stk_cal.top() == '(' && s[i] == ')')//如果左右括号配对 
				stk_cal.pop();//弹出左括号 不压栈 
			else 
				stk_cal.push(s[i]);//运算符压栈 
		}
	}
	cout<<stk_num.top();//最后数字栈栈顶的值就是算式的结果 
	return 0;
}
