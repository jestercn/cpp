#include <bits/stdc++.h>
using namespace std;
//������ʵ��
//ÿ��ɾ��һ��Ԫ�أ���Ҫ�ƶ�����
//ʱ�临�Ӷ�O(n^2)
int main()
{
    int a[10000], sel = 0;//selָ��Ҫɾ����Ԫ��
    int n, m, len;
    cin>>n>>m;
    len = n;//���鳤��
    for(int i = 0; i < n; ++i)//��1,2,...,n�������a
        a[i] = i+1;
    for(int i = 0; i < n; ++i)
    {
        sel = (sel + m - 1) % len;//�ҵ���һ����ɾ��Ԫ�ص��±�
        cout<<a[sel]<<' ';
        for(int j = sel; j <= len - 2; ++j)//ɾ������Ԫ��
            a[j] = a[j+1];
        len--;
    }
}

/*
//��ѭ������ʵ��
//ѭ������û��ͷ���
//ʱ�临�Ӷ�O(m*n)
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
    int lastP, np;//lastP��һ���ڵ�ĵ�ַ npһʱȡ���Ľڵ�ĵ�ַ
    int firstP = p++;//��һ���ڵ��λ��
    node[np].val = 1;
    lastP = firstP;
    for(int i = 2; i <= n; ++i)
    {
        //����ѭ������
        np = p++;
        node[np].val = i;
        node[lastP].next = np;
        lastP = np;
    }
    node[lastP].next = firstP;//���һ���ڵ��nextָ���һ���ڵ�

    int selP = lastP, delP;//����selP����һ������firstP���ж��Ƿ�Ҫɾ��selP����һ���ڵ�, delP����ɾ���Ľڵ�
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m-1; ++j)//�ӵ�1�ڵ㿴����m�ڵ㣬�������¿�m-1���ڵ�
            selP = node[selP].next;
        //��ʱselP����һ������Ӧ��ɾ���Ľڵ�
        delP = node[selP].next;
        node[selP].next = node[delP].next;
        cout<<node[delP].val<<' ';
        //ɾ����selP����һ���ڵ㣬��������Ҫ����m���ڵ��еĵ�һ��
    }
	return 0;
}
*/
