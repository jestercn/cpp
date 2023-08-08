#include<bits/stdc++.h>
using namespace std;
#define N 100000
typedef struct Node
{
    int x, t;//xλ�� tʱ��
    Node(){}
    Node(int a, int b):x(a), t(b){}
}Node;
//������ũ��ÿ��һ����x�������ߵ���һ������:x-1,x+1,2x����������չ��ʽ���й���
int n, k;
Node que[2*N];//���� 
int head, tail;//����ͷ��β 
bool vis[N+5];
//���Ž�xλ����ӽ����� 
void tryAddToQue(int x, int t)
{
    if(x >= 0 && x <= N && vis[x] == false)
    {
        vis[x] = true;
        que[++tail] = Node(x, t);
    }
}

//����ץ��ţ��Ҫ�õ���Сʱ��
int bfs()
{
    vis[n] = true;
    que[++tail] = Node(n, 0);
    while(head != tail)
    {
        Node sel = que[++head];
        if(sel.x == k)
			return sel.t; 
        int t = sel.t + 1, x = sel.x;
        tryAddToQue(x + 1, t);//�ֱ���ȥ�������ܴﵽ��λ�� 
        tryAddToQue(x - 1, t);
        tryAddToQue(2 * x, t);
    }
}

int main()
{
    cin>>n>>k;
    cout<<bfs();
    return 0;
}
