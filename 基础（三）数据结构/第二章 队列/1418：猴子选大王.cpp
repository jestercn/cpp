#include <bits/stdc++.h>
using namespace std;
//考点：循环链表
//如果用顺序表的话，时间复杂度是O(n^2)，本题n为1e6，O(n^2)的复杂度无法承受
//如果用循环链表，那么时间复杂度为O(n*m)，本题m为100，总体运算次数最大为10^8，大概能满足需求 
//对于10^6规模级别的输入 用cin会超时，只能用scanf 
typedef struct Node
{
	int val;
	int next;
}Node;
Node node[1000005];//静态链表 
int p; 
int head = p++;//申请一个头结点 
int tail = head;
int x[1000005];
int main()
{
	int n, np;//np：新节点的地址 
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &x[i]);//输入x[i] 对于10^6规模级别的输入 用cin会超时，只能用scanf 
		np = p++;//尾插法添加元素
		node[np].val = i;
		node[tail].next = np; 
		tail = np;
	}
	node[tail].next = node[head].next;//把头结点略过，构成无头结点的循环链表
	head = node[tail].next;//head重新指向val为1的节点
	while(head != tail)//head == tail时，循环链表中，只有一个节点 
	{
		//自己为1，下一个为2，报到第x[i]号，那么实际是向后取x[i]-1次
		int times =  x[node[head].val] - 1;
		for(int i = 0; i < times; ++i)
		{
			tail = head;//head指向要删除的节点，tail始终指向head前一个节点
			head = node[head].next;
		}
		//此时应删除node[head]
		node[tail].next = node[head].next;
		head = node[tail].next;
	}
	cout<<node[head].val;
}
