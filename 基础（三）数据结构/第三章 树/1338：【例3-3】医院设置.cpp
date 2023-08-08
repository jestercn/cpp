#include <bits/stdc++.h>
using namespace std;
//���Ȿ������ͼ�ı�������
//ʹ�ô���ָ��˫�׽��ָ���������� 
typedef struct
{
	int val;//����
	int left, right, parent;
}Node;
Node node[200]; 

bool vis[200];//��ʾ������Ƿ��ѷ��ʹ�
int dist[200];//��ʾ��������ĳ���ľ���
 
//�ڵ�fromp��㴦��ҽԺ��������˵�ҽԺ�ľ��룬����dist������ 
//����Ϊ��fromp�������������������
//distance��fromp����������������ж�Զ�ľ��� 
int getDistance(int fromp, int distance)
{
	vis[fromp] = true;
	dist[fromp] = distance;
	int selp = node[fromp].parent;
	if(selp != 0 && vis[selp] == false)
		getDistance(selp, distance + 1);
	selp = node[fromp].left;
	if(selp != 0 && vis[selp] == false)
		getDistance(selp, distance + 1);
	selp = node[fromp].right;
	if(selp != 0 && vis[selp] == false)
		getDistance(selp, distance + 1);
}

//������ 
int sumDis(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; ++i)
	{
		sum += node[i].val * dist[i];
	}
	return sum;
}

int main()
{
	int n, val, left, right, min = INT_MAX, sum;
	cin>>n; 
	for(int i = 1; i <= n; ++i)//��i�Ž��洢��node[i]
	{
		cin>>val>>left>>right;
		node[i].val = val;//����i��� 
		node[i].left = left;
		node[i].right = right;
		if(left != 0)//��i������Һ��ӵ�˫����Ϊi 
			node[left].parent = i;
		if(right != 0)
			node[right].parent = i;
	}
	for(int i = 1; i <= n; ++i)
	{
		memset(vis, false, sizeof(vis));
		memset(dist, 0, sizeof(dist));
		getDistance(i, 0);
		sum = sumDis(n);
		if(sum < min)
			min = sum; 
	}
	cout<<min;
	return 0;
}
