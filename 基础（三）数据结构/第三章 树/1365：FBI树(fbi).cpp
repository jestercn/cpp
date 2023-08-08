#include<bits/stdc++.h>
using namespace std;
//字符串最大长度为2^10 = 1024 
//可能用到的结点数：一个叶子结点点有2^10的满二叉树共有多少个结点？为2^0+2^1+...+2^10 = 2^11-1 = 2047，因此结点池大小设为2050 
typedef struct 
{
	char s[1030];
	int left, right;
}Node;
Node node[2050];
int p=1;

char strType(char s[])
{
	bool has0 = false, has1 = false;
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == '0')
			has0 = true;
		if(s[i] == '1')
			has1 = true;
		if(has0 && has1)
			return 'F';
	}
	if(has0)
		return 'B';
	if(has1)
		return 'I';
}

int createTree(char s[])
{
	int np = p++;
	strcpy(node[np].s, s);
	int len = strlen(s), i;
	if(len <= 1)
		return np;
	else
	{
		char s1[550], s2[550];//最大为1024的一半，设为550 
		//将s分为两半，构造两个字符串 
		for(i = 0; i < len / 2; ++i)
			s1[i] = s[i];
		s1[i] = '\0';
		for(i = len / 2; i <= len - 1; ++i)
			s2[i - len / 2] = s[i];
		s2[i - len / 2] = '\0';
		node[np].left = createTree(s1);
		node[np].right = createTree(s2);
		return np;
	}
}

void postOrder(int p_r)
{
	if(p_r != 0)
	{
		postOrder(node[p_r].left);
		postOrder(node[p_r].right);
		cout<<strType(node[p_r].s);
	}
}

int main()
{
	int n;
	cin>>n;
	char s[1030];
	cin>>s;
	int p_root = createTree(s);	
	postOrder(p_root);
    return 0;
}
