#include<bits/stdc++.h>
using namespace std; 
char str[105], sign[105];//str:输入的字符串 sign:标记字符串
 
//已知一个左括号的位置，寻找和它匹配的右括号，并标记 
//l:左括号的位置
//返回值：下一次搜索的起始位置，如果返回值是0，那么停止这次搜索 
int Search(int l)
{ 
	int i = l+1;
	while(i < strlen(str))
	{
		if(str[i] == ')')//如果遇到右括号，则退出这次搜索 
		{
			return i+1;//下次应该从右括号下一个位置开始搜索 
		}
		else if(str[i] == '(')//如果遇到左括号，则开启下一次搜索 
		{	
			i = Search(i);//如果str[i]位置的左括号都无法匹配，那么在它前面的str[l]位置的左括号当然也无法匹配。
			//Search(i)会返回strlen(str), i==strlen(str)时会跳出循环。接下来标记l位置的括号不能匹配。 
		}
		else
			i++;
	}
	sign[l] = '$';//能运行到这里，表明l位置的左括号是不能匹配的 
	return strlen(str);
}

//把sign字符串的元素都设为空格，len的位置设为'\0'，使其成为字符串 
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
			if(str[i] == '(')//开始搜索与这一左括号匹配的右括号 
				i = Search(i);
			else if(str[i] == ')')//遇到没法匹配的右括号 
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
