#include <bits/stdc++.h>
using namespace std;
//���㣺ѭ������
//�����˳���Ļ���ʱ�临�Ӷ���O(n^2)������nΪ1e6��O(n^2)�ĸ��Ӷ��޷�����
//�����ѭ��������ôʱ�临�Ӷ�ΪO(n*m)������mΪ100����������������Ϊ10^8��������������� 
//����10^6��ģ��������� ��cin�ᳬʱ��ֻ����scanf 
typedef struct Node
{
	int val;
	int next;
}Node;
Node node[1000005];//��̬���� 
int p; 
int head = p++;//����һ��ͷ��� 
int tail = head;
int x[1000005];
int main()
{
	int n, np;//np���½ڵ�ĵ�ַ 
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &x[i]);//����x[i] ����10^6��ģ��������� ��cin�ᳬʱ��ֻ����scanf 
		np = p++;//β�巨���Ԫ��
		node[np].val = i;
		node[tail].next = np; 
		tail = np;
	}
	node[tail].next = node[head].next;//��ͷ����Թ���������ͷ����ѭ������
	head = node[tail].next;//head����ָ��valΪ1�Ľڵ�
	while(head != tail)//head == tailʱ��ѭ�������У�ֻ��һ���ڵ� 
	{
		//�Լ�Ϊ1����һ��Ϊ2��������x[i]�ţ���ôʵ�������ȡx[i]-1��
		int times =  x[node[head].val] - 1;
		for(int i = 0; i < times; ++i)
		{
			tail = head;//headָ��Ҫɾ���Ľڵ㣬tailʼ��ָ��headǰһ���ڵ�
			head = node[head].next;
		}
		//��ʱӦɾ��node[head]
		node[tail].next = node[head].next;
		head = node[tail].next;
	}
	cout<<node[head].val;
}
