#include<bits/stdc++.h>
using namespace std;

int main()
{
    //将输入分割单词
    char s[205][105];//s[i]保存一个单词字符串 
    char c;//读入的字符 
    int w = 0;//单词下标 
    int i = 0;//单词中字母下标
    
	//读入每个字母，构成单词并存入s中 
    c = getchar();
    while(c != '\n')
    {
        if(c != ' ' && c != ',')
        {
            s[w][i++] = c;
        }
        else
        {
        	if(i != 0)//防止出现连续空格或逗号的情况 
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
    int wordNum = w;//单词总数量 

	//求最大最小值 
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
