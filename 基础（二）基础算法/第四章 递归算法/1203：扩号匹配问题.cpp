#include<bits/stdc++.h>
using namespace std; 
char str[105], sign[105];//str:������ַ��� sign:����ַ���
 
//��֪һ�������ŵ�λ�ã�Ѱ�Һ���ƥ��������ţ������ 
//l:�����ŵ�λ��
//����ֵ����һ����������ʼλ�ã��������ֵ��0����ôֹͣ������� 
int Search(int l)
{ 
	int i = l+1;
	while(i < strlen(str))
	{
		if(str[i] == ')')//������������ţ����˳�������� 
		{
			return i+1;//�´�Ӧ�ô���������һ��λ�ÿ�ʼ���� 
		}
		else if(str[i] == '(')//������������ţ�������һ������ 
		{	
			i = Search(i);//���str[i]λ�õ������Ŷ��޷�ƥ�䣬��ô����ǰ���str[l]λ�õ������ŵ�ȻҲ�޷�ƥ�䡣
			//Search(i)�᷵��strlen(str), i==strlen(str)ʱ������ѭ�������������lλ�õ����Ų���ƥ�䡣 
		}
		else
			i++;
	}
	sign[l] = '$';//�����е��������lλ�õ��������ǲ���ƥ��� 
	return strlen(str);
}

//��sign�ַ�����Ԫ�ض���Ϊ�ո�len��λ����Ϊ'\0'��ʹ���Ϊ�ַ��� 
void resetSign(int len)
{
	for(int i = 0; i < len; ++i)
		sign[i] = ' ';
	sign[len] = '\0';
} 

int main()
{
	while(cin>>str)
	{
		resetSign(strlen(str));
		int i = 0;
		while(i < strlen(str))
		{
			if(str[i] == '(')//��ʼ��������һ������ƥ��������� 
				i = Search(i);
			else if(str[i] == ')')//����û��ƥ��������� 
			{
				sign[i] = '?';
				i++;
			}
			else
				i++;
		}
		cout<<str<<endl;
		cout<<sign<<endl;
	}
}
