#include<bits/stdc++.h>
using namespace std;
/*˼·:��һ������ջ��һ�������ջ��������ɨ����ʽ�ַ��������������ַ��������������ַ�����Ϊ���֣���������ѹ������ջ��
����������������������������ѹ�������ջ����������ȼ�:������ С�� �Ӽ� С�� �˳� С�� �˷� С�� ������
����ѹ�������������ȼ�������ջ������������ȼ�����ѹ�롣
����ѹ�������������ȼ���С�ڵ���ջ������������ȼ�������ж�Ρ��������㡱��ֱ������ѹջ�� 
���������㡱������ȡջ�������c������ջ��ջ����b����ջ����a����a��b����c������ֵ������һֵѹ������ջ

����ѹ����������ţ���ʱ�����ջ���������ţ���ô�����ջ��ջ
ɨ���ַ����󣬲��Ͻ��С��������㡱�������ջΪ��ʱ������ջ��ջ��ֵ�������ս�� 
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
		case '^':
			return (int)pow(a,b);
	}	
}

int main()
{
	int n;
	char s[300];
	cin>>s;//����������ǺϷ��ı��ʽ 
	int len = strlen(s);
	s[len] = ')';//ȡ�ɣ���һ�����ȼ���͵ķ���')'�ӵ��ַ���ĩβ����ʹ������ļ��㡣 
	int num = 0;
	stack<int> stk_num;//����ջ 
	stack<char> stk_cal;//�����ջ 
	bool isFormingNum = false;//��־λ ��ʾ�Ƿ����ڹ������� 
	for(int i = 0; i <=len; ++i)
	{
		if(s[i] >= '0' && s[i] <= '9')//���ɨ�赽���� 
		{
			isFormingNum = true;
			num = num * 10 + s[i] - '0';//���ַ���ת��Ϊ�� 
		}
		else//���ɨ�赽����� 
		{
			if(isFormingNum)
			{
				stk_num.push(num);//������õ�����ѹ������ջ 
				num = 0;//�������ֵı�����ԭ
				isFormingNum = false;
			}
			//����ѹ�������������ȼ���С�ڵ���ջ������������ȼ�������ж�Ρ��������㡱��ֱ������ѹջ�������������� �������  
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
			if(stk_cal.empty() == false && stk_cal.top() == '(' && s[i] == ')')//�������������� 
				stk_cal.pop();//���������� ��ѹջ 
			else 
				stk_cal.push(s[i]);//�����ѹջ 
		}
	}
	cout<<stk_num.top();//�������ջջ����ֵ������ʽ�Ľ�� 
	return 0;
}
