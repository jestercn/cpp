#include<bits/stdc++.h>
using namespace std;
/*思路:
一、先判断表达式是否合法：
1. 括号匹配：扫描整个算式，遇到左括号就入栈，遇到右括号，就出栈一次。在这一过程中，如果栈空了，还遇到右括号，那么表达式非法。 
2. 对于负号：行首的负号，以及'('后的负号，前面插入'0'
3. 检查是否有连续出现的运算符()+-/*@
")("不允许，允许第一个字符是'('或第二个字符是')'。其他两个字符连续的情况都不允许 
第一个字符不可以是运算符，除了'('
最后一个字符不可以是运算符，除了')' 

设一个栈stk_cal用于存储运算符,一个字符数组pstExp用于存储后缀表达式 
从左到右扫描算式字符串，如果读到数字字符，就构造数字，遇到运算符时，数字构造完成，将数字添加到pstExp尾部 
读到运算符，
1. 如果栈空，该运算符压入stk_cal
2. 如果该运算符优先级高于栈顶运算符，压入stk_cal
3. 如果该运算符优先级低于或等于栈顶运算符，那么stk_cal出栈，将出栈的运算符加到pstExp尾部，直到stk_cal栈顶运算符高于这个运算符，或栈空。 
4. 如果该运算符是右括号，stk_cal栈顶是左括号，stk_cal出栈
字符串都扫描结束后，将stk_cal中的所有运算符都出栈，并加到pstExp尾部

本程序用一个整形数组保存后缀表达式，用负数表示运算符，在输出时做转换。

计算后缀表达式的值：后缀表达式从前向后遍历，遇到数字入栈，遇到运算符，则出栈两个数，结合运算符做运算，然后将结果入栈 
*/

//判断括号是否匹配 
bool isBracketValid(char s[])
{
	stack<char> stk;//判断括号是否匹配的栈 
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == '(')
			stk.push(s[i]);
		else if(s[i] == ')')
		{
			if(stk.empty() == false)
				stk.pop();
			else
				return false;//如果有右括号且栈空，那么说明有右括号没有匹配 
		}
	}
	if(stk.empty() == false)//如果栈不空，说明有左括号没有匹配 
		return false;
	else
		return true;
}
//字符串第x个位置插入元素c
void strInsert(char s[], int x, char c)
{
	for(int i = strlen(s); i >=x; --i)
	{
		s[i+1] = s[i];
	}
	s[x] = c;
}
//行首的负号，以及'('后的负号，前面插入'0'
void addZero(char s[])
{
	if(s[0] == '-')
		strInsert(s, 0, '0');
	for(int i = strlen(s)-1; i >= 1; --i)//插入时会改变字符数组的长度，因此要从后向前扫描 
	{
		if(s[i] == '-' && s[i-1] == '(')
			strInsert(s, i, '0');
	}
}
//判断一个字符是否是运算符 
bool isCal(char c)
{
	if(c == '+' || c == '-' || c == '*' ||c == '/' || c == '(' || c == ')')
		return true;
	else
		return false; 
}
//判断是否有非法的连续运算符 
bool isCalValid(char s[])
{
	int len = strlen(s);
	if(isCal(s[0]) && s[0]!='(')
		return false;
	if(isCal(s[len-1]) && s[len-1]!=')')
		return false;
	for(int i = 1; i < strlen(s); ++i)
	{
		if(isCal(s[i]) && isCal(s[i-1]))
		{
			if(s[i-1] == ')' && s[i] == '(')//两个连续的字符形成")("时，非法 
				return false;
			else if(s[i-1] == ')' || s[i] == '(')
				;//除了上面的情况，第一个字符是左括号，或第二个字符是右括号，都可以通过 
			else
				return false; 
		}
	}
	return true; 
}
//检查中缀算式是否合法，并在负号前加0 
bool isValid(char s[])
{
	if(isBracketValid(s) == false)
		return false;	
	addZero(s);
	if(isCalValid(s))
		return true;
	else
		return false;	
}
//获取运算符优先级 
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
	}	
}
//由整数表示运算符，负数-x表示ASCII码为x的运算符。这样的整数和字符间的转换。 
int calToInt(char c)
{
	return -(int)c;
}
char intToCal(int a)
{
	return char(-a);
}
//输出后缀表达式 
void printPstExp(vector<int> s)
{
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] < 0)
			cout<<intToCal(s[i])<<' ';
		else
			cout<<s[i]<<' ';
	}
	cout<<endl;
}
//计算后缀表达式的值 
int calcPstExp(vector<int> s)
{
	stack<int> stk;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] >= 0)//s[i]大于0，是数字 
			stk.push(s[i]);
		else//s[i]小于0，是运算符，开始运算 
		{
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();
			char c = intToCal(s[i]);
			stk.push(calc(a, b, c));
		}
	}
	return stk.top();
}

int main()
{
	int n, num = 0;
	char s[1000];//s:中缀表达式字符串 
	bool isForming = false;
	vector<int> pstExp;//由整数表示的 后缀表达式 其中的负数-x表示ASCII码为x的运算符 
	cin>>s;
	s[strlen(s)-1] = '\0';//把最后的'@'覆盖了 
	if(isValid(s) == false)
	{
		cout<<"NO";
		return 0;
	}
	
	s[strlen(s)+1] = '\0';//在算式字符串末尾添加')'，为了最后读入一个优先级最低的运算符，促使完成转换。
	s[strlen(s)] = ')';	
	
	stack<char> stk_cal;
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] >= '0' && s[i] <= '9')//如果是数字字符，则构成数字 
		{
			isForming = true;
			num = num * 10 + s[i] - '0';
		}
		else
		{
			if(isForming)//如果正在形成数字时，遇上运算符 
			{
				pstExp.push_back(num);//形成的数字进入后缀表达式 
				num = 0;
				isForming = false;
			}
			do
			{ 
				//运算符栈空，压栈 或 该运算符比栈顶运算符优先级高，压栈 
				if(stk_cal.empty() || isSuperior(s[i], stk_cal.top()))
				{
					stk_cal.push(s[i]);
					break;
				}
 				else if(stk_cal.top() == '(')
 				{
 					if(s[i] == ')')//左右括号配对，左括号出栈 
						stk_cal.pop();
					else//栈顶是左括号时，除了右括号，什么运算符都可以压栈 
						stk_cal.push(s[i]);
					break;
				}
				else//如果要压栈的运算符优先级小于等于栈顶运算符 
				{
					pstExp.push_back(calToInt(stk_cal.top()));//栈顶运算符加入后缀表达式 
					stk_cal.pop();
				}
			}while(true);
		}
	}
	//printPstExp(pstExp);//打印后缀表达式 
	cout<<calcPstExp(pstExp);//后缀表达式求值 
	return 0;
}

