#include<bits/stdc++.h>
using namespace std;

int main()
{
    //������ָ��
    char s[205][105];//s[i]����һ�������ַ��� 
    char c;//������ַ� 
    int w = 0;//�����±� 
    int i = 0;//��������ĸ�±�
    
	//����ÿ����ĸ�����ɵ��ʲ�����s�� 
    c = getchar();
    while(c != '\n')
    {
        if(c != ' ' && c != ',')
        {
            s[w][i++] = c;
        }
        else
        {
        	if(i != 0)//��ֹ���������ո�򶺺ŵ���� 
        	{
	            s[w][i] = '\0';
	            w++;
	            i = 0;
        	}
        }
        c = getchar();
    }
    s[w][i] = '\0';
    w++;
    int wordNum = w;//���������� 

	//�������Сֵ 
    int maxlen = 0, minlen = 200; 
    int max_i, min_i;
    for(int i = 0; i < wordNum; ++i)
    {
        if(strlen(s[i]) > maxlen)
        {
           max_i = i;
           maxlen = strlen(s[i]);
        }
        if(strlen(s[i]) < minlen)
        {
           min_i = i;
           minlen = strlen(s[i]);
        }
    }
    puts(s[max_i]);
    puts(s[min_i]);
}
