#include <bits/stdc++.h>
using namespace std;
//���� ǰi�����ֵĺ�%k==j, ����i��������v���� (ǰi-1�����ֵĺ� + v)%k == j
//�����У�ǰi-1�����ֵĺ�%k == (j + v) % k �� (k + j - v%k)%k
//f[i][j]��ʾǰi�����֣������������ĺͽ��ģk�ܷ�õ�j
//�е��ƹ�ʽ: f[i][j] = f[i-1][(j+v)%k] || f[i-1][(k+j-v%k)%k] 
bool f[10005][105];//f[i][j]��ʾǰi�����֣������������ĺͽ��ģk�ܲ��ܵõ�j 
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
//����+��ϣ��� 
typedef struct Node
{
	int i, val;//i:�ڼ��������ɵ� val��ֵ
	Node(){};
	Node(int a, int b):i(a),val(b){} 
}Node;
int flag[105];//flag[i] = m���ӵ���m������ʱ����ʽ��ֵval����:val%k = i 
int n, k;
//��num��kȡģ�Ľ��������ȡģ�Ľ��ʾ����0 % 3 = 0, -1 % 3 = 2, -2 % 3 = 1, -3 % 3 = 0  
int modk(int num)
{
	if(num >= 0)
		return num % k;
	else
		return k + num % k;
}

int main()
{
	int a;//a:������� val����ʽ��ʱ��ֵ 
	cin>>n>>k;
	queue<Node> que;
	que.push(Node(0,0));//ʹ�������ѭ���ͳ�����ܹ���ʼ��ת 
	for(int i = 1; i <= n; ++i)//i:�����i���� 
	{
		cin>>a;
		Node sel = que.front(); 
		while(sel.i == i - 1)//�������һ���������ɵ�ֵ 
		{
			que.pop();//����
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
	if(flag[0] == n)//�㵽��n����ʱ�������0ֵ�����ʹflag[0] = n����ʱ����һ�����п���ʹ������ʽ��ֵ%k == 0 
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
*/
