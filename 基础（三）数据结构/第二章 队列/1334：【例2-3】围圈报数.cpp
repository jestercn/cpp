#include <bits/stdc++.h>
using namespace std;
//用数组实现
//每次删除一个元素，需要移动数组
//时间复杂度O(n^2)
int main()
{
    int a[10000], sel = 0;//sel指向要删除的元素
    int n, m, len;
    cin>>n>>m;
    len = n;//数组长度
    for(int i = 0; i < n; ++i)//用1,2,...,n填充数组a
        a[i] = i+1;
    for(int i = 0; i < n; ++i)
    {
        sel = (sel + m - 1) % len;//找到下一个待删除元素的下标
        cout<<a[sel]<<' ';
        for(int j = sel; j <= len - 2; ++j)//删除数组元素
            a[j] = a[j+1];
        len--;
    }
}

/*
//用循环链表实现
//循环链表没有头结点
//时间复杂度O(m*n)
typedef struct Node
{
    int val;
    int next;
}Node;

Node node[10000];
int p;

int main()
{
    int n, m;
    cin>>n>>m;
    int lastP, np;//lastP上一个节点的地址 np一时取到的节点的地址
    int firstP = p++;//第一个节点的位置
    node[np].val = 1;
    lastP = firstP;
    for(int i = 2; i <= n; ++i)
    {
        //构建循环链表
        np = p++;
        node[np].val = i;
        node[lastP].next = np;
        lastP = np;
    }
    node[lastP].next = firstP;//最后一个节点的next指向第一个节点

    int selP = lastP, delP;//现在selP的下一个就是firstP，判断是否要删掉selP的下一个节点, delP：待删除的节点
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m-1; ++j)//从第1节点看到第m节点，就是向下看m-1个节点
            selP = node[selP].next;
        //此时selP的下一个就是应该删除的节点
        delP = node[selP].next;
        node[selP].next = node[delP].next;
        cout<<node[delP].val<<' ';
        //删除后，selP的下一个节点，就是下面要看的m个节点中的第一个
    }
	return 0;
}
*/
