#include <bits/stdc++.h>
using namespace std;
//若想 前i个数字的和%k==j, 若第i个数字是v，则 (前i-1个数字的和 + v)%k == j
//必须有：前i-1个数字的和%k == (j + v) % k 或 (k + j - v%k)%k
//f[i][j]表示前i个数字（无论正负）的和结果模k能否得到j
//有递推公式: f[i][j] = f[i-1][(j+v)%k] || f[i-1][(k+j-v%k)%k] 
bool f[10005][105];//f[i][j]表示前i个数字（无论正负）的和结果模k能不能得到j 
int main()
{
	int n, k, v;
	cin>>n>>k;
	f[0][0] = true;
	for(int i = 1; i <= n; ++i)
	{
		cin>>v;
		for(int j = 0; j < k; ++j)
		{
			f[i][j] = f[i-1][(j+v)%k] || f[i-1][(k+j-v%k)%k]; 
		}
	}
	if(f[n][0])
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
/* 
//队列+哈希标记 
typedef struct Node
{
	int i, val;//i:第几个数生成的 val：值
	Node(){};
	Node(int a, int b):i(a),val(b){} 
}Node;
int flag[105];//flag[i] = m：加到第m个数字时，算式的值val满足:val%k = i 
int n, k;
//求num对k取模的结果，负数取模的结果示例：0 % 3 = 0, -1 % 3 = 2, -2 % 3 = 1, -3 % 3 = 0  
int modk(int num)
{
	if(num >= 0)
		return num % k;
	else
		return k + num % k;
}

int main()
{
	int a;//a:读入的数 val：算式临时的值 
	cin>>n>>k;
	queue<Node> que;
	que.push(Node(0,0));//使得下面的循环和出入队能够开始运转 
	for(int i = 1; i <= n; ++i)//i:读入第i个数 
	{
		cin>>a;
		Node sel = que.front(); 
		while(sel.i == i - 1)//如果是上一个数字生成的值 
		{
			que.pop();//出队
			int v1 = modk(sel.val + a), v2 = modk(sel.val - a);
			if(flag[v1] != i)
			{
				flag[v1] = i;
				que.push(Node(i, v1));
			}
			if(flag[v2] != i)
			{
				flag[v2] = i;
				que.push(Node(i, v2));
			}
			sel = que.front();	
		}
	}	
	if(flag[0] == n)//算到第n个数时，能求出0值，则会使flag[0] = n，此时存在一种序列可以使整体算式的值%k == 0 
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
*/
