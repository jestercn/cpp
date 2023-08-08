#include<bits/stdc++.h>
using namespace std;
/*˼·:
һ�����жϱ��ʽ�Ƿ�Ϸ���
1. ����ƥ�䣺ɨ��������ʽ�����������ž���ջ�����������ţ��ͳ�ջһ�Ρ�����һ�����У����ջ���ˣ������������ţ���ô���ʽ�Ƿ��� 
2. ���ڸ��ţ����׵ĸ��ţ��Լ�'('��ĸ��ţ�ǰ�����'0'
3. ����Ƿ����������ֵ������()+-/*@
")("�����������һ���ַ���'('��ڶ����ַ���')'�����������ַ������������������ 
��һ���ַ��������������������'('
���һ���ַ��������������������')' 

��һ��ջstk_cal���ڴ洢�����,һ���ַ�����pstExp���ڴ洢��׺���ʽ 
������ɨ����ʽ�ַ�����������������ַ����͹������֣����������ʱ�����ֹ�����ɣ���������ӵ�pstExpβ�� 
�����������
1. ���ջ�գ��������ѹ��stk_cal
2. �������������ȼ�����ջ���������ѹ��stk_cal
3. �������������ȼ����ڻ����ջ�����������ôstk_cal��ջ������ջ��������ӵ�pstExpβ����ֱ��stk_calջ�����������������������ջ�ա� 
4. �����������������ţ�stk_calջ���������ţ�stk_cal��ջ
�ַ�����ɨ������󣬽�stk_cal�е��������������ջ�����ӵ�pstExpβ��

��������һ���������鱣���׺���ʽ���ø�����ʾ������������ʱ��ת����

�����׺���ʽ��ֵ����׺���ʽ��ǰ������������������ջ����������������ջ���������������������㣬Ȼ�󽫽����ջ 
*/

//�ж������Ƿ�ƥ�� 
bool isBracketValid(char s[])
{
	stack<char> stk;//�ж������Ƿ�ƥ���ջ 
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == '(')
			stk.push(s[i]);
		else if(s[i] == ')')
		{
			if(stk.empty() == false)
				stk.pop();
			else
				return false;//�������������ջ�գ���ô˵����������û��ƥ�� 
		}
	}
	if(stk.empty() == false)//���ջ���գ�˵����������û��ƥ�� 
		return false;
	else
		return true;
}
//�ַ�����x��λ�ò���Ԫ��c
void strInsert(char s[], int x, char c)
{
	for(int i = strlen(s); i >=x; --i)
	{
		s[i+1] = s[i];
	}
	s[x] = c;
}
//���׵ĸ��ţ��Լ�'('��ĸ��ţ�ǰ�����'0'
void addZero(char s[])
{
	if(s[0] == '-')
		strInsert(s, 0, '0');
	for(int i = strlen(s)-1; i >= 1; --i)//����ʱ��ı��ַ�����ĳ��ȣ����Ҫ�Ӻ���ǰɨ�� 
	{
		if(s[i] == '-' && s[i-1] == '(')
			strInsert(s, i, '0');
	}
}
//�ж�һ���ַ��Ƿ�������� 
bool isCal(char c)
{
	if(c == '+' || c == '-' || c == '*' ||c == '/' || c == '(' || c == ')')
		return true;
	else
		return false; 
}
//�ж��Ƿ��зǷ������������ 
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
			if(s[i-1] == ')' && s[i] == '(')//�����������ַ��γ�")("ʱ���Ƿ� 
				return false;
			else if(s[i-1] == ')' || s[i] == '(')
				;//����������������һ���ַ��������ţ���ڶ����ַ��������ţ�������ͨ�� 
			else
				return false; 
		}
	}
	return true; 
}
//�����׺��ʽ�Ƿ�Ϸ������ڸ���ǰ��0 
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
//��ȡ��������ȼ� 
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
//�����c1�Ƿ�������c2���ȼ����� 
bool isSuperior(char c1, char c2)
{
	return getCalNum(c1) > getCalNum(c2);
}
//�������� 
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
//��������ʾ�����������-x��ʾASCII��Ϊx����������������������ַ����ת���� 
int calToInt(char c)
{
	return -(int)c;
}
char intToCal(int a)
{
	return char(-a);
}
//�����׺���ʽ 
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
//�����׺���ʽ��ֵ 
int calcPstExp(vector<int> s)
{
	stack<int> stk;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] >= 0)//s[i]����0�������� 
			stk.push(s[i]);
		else//s[i]С��0�������������ʼ���� 
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
	char s[1000];//s:��׺���ʽ�ַ��� 
	bool isForming = false;
	vector<int> pstExp;//��������ʾ�� ��׺���ʽ ���еĸ���-x��ʾASCII��Ϊx������� 
	cin>>s;
	s[strlen(s)-1] = '\0';//������'@'������ 
	if(isValid(s) == false)
	{
		cout<<"NO";
		return 0;
	}
	
	s[strlen(s)+1] = '\0';//����ʽ�ַ���ĩβ���')'��Ϊ��������һ�����ȼ���͵����������ʹ���ת����
	s[strlen(s)] = ')';	
	
	stack<char> stk_cal;
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] >= '0' && s[i] <= '9')//����������ַ����򹹳����� 
		{
			isForming = true;
			num = num * 10 + s[i] - '0';
		}
		else
		{
			if(isForming)//��������γ�����ʱ����������� 
			{
				pstExp.push_back(num);//�γɵ����ֽ����׺���ʽ 
				num = 0;
				isForming = false;
			}
			do
			{ 
				//�����ջ�գ�ѹջ �� ���������ջ����������ȼ��ߣ�ѹջ 
				if(stk_cal.empty() || isSuperior(s[i], stk_cal.top()))
				{
					stk_cal.push(s[i]);
					break;
				}
 				else if(stk_cal.top() == '(')
 				{
 					if(s[i] == ')')//����������ԣ������ų�ջ 
						stk_cal.pop();
					else//ջ����������ʱ�����������ţ�ʲô�����������ѹջ 
						stk_cal.push(s[i]);
					break;
				}
				else//���Ҫѹջ����������ȼ�С�ڵ���ջ������� 
				{
					pstExp.push_back(calToInt(stk_cal.top()));//ջ������������׺���ʽ 
					stk_cal.pop();
				}
			}while(true);
		}
	}
	//printPstExp(pstExp);//��ӡ��׺���ʽ 
	cout<<calcPstExp(pstExp);//��׺���ʽ��ֵ 
	return 0;
}

