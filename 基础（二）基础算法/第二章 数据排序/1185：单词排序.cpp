#include <bits/stdc++.h>
using namespace std;
//˼·���ȱ����ַ������Ѹ������ʴ���һ����ά�����У�����Ĺ�����ʹ�ò�������
//���ʱ��������ĵ��ʺ���һ������һ������������������Ա�֤��ͬ�ĵ���ֻ���1�� 
int main()
{
	char words[101][55], tword[55], temp[55];//��ά���鱣�������� 
	int t_i = 0, w_i = 0;//t_i:tword�е��±� w_i:words�е��±� 
	while(cin>>tword)//ֻ���������ļ��ķ�ʽ��������д�� 
	{
		strcpy(words[w_i], tword);
		for(int j = w_i; j >= 1; --j)//�������� 
		{
			if(strcmp(words[j], words[j-1]) < 0)//������浥�ʵı������С����ô��ǰ��ĵ��ʵ��� 
			{
				strcpy(temp, words[j]);
				strcpy(words[j], words[j-1]);
				strcpy(words[j-1], temp);
			}
			else
				break;
		}
		w_i++;
	}
	strcpy(temp, "");//��temp������һ��ȡ���ĵ��� 
	for(int i = 0; i < w_i; ++i)//������ĵ��ʺ���һ������һ���������
	{
		if(strcmp(words[i], temp) != 0)
		{
			cout<<words[i]<<endl;
			strcpy(temp, words[i]);
		}
	}
}
