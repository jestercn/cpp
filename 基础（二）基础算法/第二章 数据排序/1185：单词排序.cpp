#include <bits/stdc++.h>
using namespace std;
//思路：先遍历字符串，把各个单词存入一个二维数组中，存入的过程中使用插入排序
//输出时，若输出的单词和上一个单词一样，则不输出。这样可以保证相同的单词只输出1次 
int main()
{
	char words[101][55], tword[55], temp[55];//二维数组保存多个单词 
	int t_i = 0, w_i = 0;//t_i:tword中的下标 w_i:words中的下标 
	while(cin>>tword)//只能用输入文件的方式调试这种写法 
	{
		strcpy(words[w_i], tword);
		for(int j = w_i; j >= 1; --j)//插入排序 
		{
			if(strcmp(words[j], words[j-1]) < 0)//如果右面单词的比左面的小，那么和前面的单词调换 
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
	strcpy(temp, "");//用temp保存上一个取到的单词 
	for(int i = 0; i < w_i; ++i)//若输出的单词和上一个单词一样，则不输出
	{
		if(strcmp(words[i], temp) != 0)
		{
			cout<<words[i]<<endl;
			strcpy(temp, words[i]);
		}
	}
}
