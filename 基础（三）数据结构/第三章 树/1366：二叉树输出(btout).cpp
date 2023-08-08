#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
	char c;
	int left, right;
	int length;//表示该结点的长度，应该输出几个字符 
}Node;
Node node[2050];
int p=1;

char s_pre[1000], s_in[1000];//先序，中序遍历字符串 

//根据先序，中序字符串遍历树 
int createTree(int sp_l, int sp_r, int si_l, int si_r)//带l,r的参数表示对应数组中截取的部分的左右侧位置，以截取到的字符串，构建树 
{
	if(sp_l > sp_r || si_l > si_r)
		return 0;
	int np = p++, count = 0, si_sel;//count 左子树结点个数 
	node[np].c = s_pre[sp_l];//先序遍历第一个输出的值是根节点的值 
	for(int i = si_l; i <= si_r; ++i)
	{
		if(s_in[i] == s_pre[sp_l])
		{
			si_sel = i;
			break;
		}
		count++;
	}
	node[np].left = createTree(sp_l + 1, sp_l + count, si_l, si_sel - 1);
	node[np].right = createTree(sp_l + count + 1, sp_r, si_sel + 1, si_r);
	return np;  
}

//计算输出字符数，存入树的结点中 
int calcLength(int p_r)
{
	if(p_r == 0)
		return 0;
	else if(node[p_r].left == 0 && node[p_r].right == 0)
	{
		node[p_r].length = 1;
		return 1;
	}
	else
	{
		node[p_r].length = calcLength(node[p_r].left) + calcLength(node[p_r].right);
		return node[p_r].length;
	}
}

//先序遍历输出 
void preOrder(int p_r)
{
	if(p_r != 0)
	{
		for(int i = 0; i < node[p_r].length; ++i)
			cout<<node[p_r].c;
		cout<<endl;
		preOrder(node[p_r].left);
		preOrder(node[p_r].right);
	}
}

int main()
{
	cin>>s_pre>>s_in;	
	int len = strlen(s_pre);
	int p_r = createTree(0, len - 1, 0, len - 1);
	calcLength(p_r);
	preOrder(p_r);
    return 0;
} 
