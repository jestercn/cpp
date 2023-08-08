#include<bits/stdc++.h>
using namespace std;
#define N 100000
typedef struct Node
{
    int x, t;//x位置 t时间
    Node(){}
    Node(int a, int b):x(a), t(b){}
}Node;
//解析：农夫每在一个点x，可以走的下一个点有:x-1,x+1,2x，以这种扩展方式进行广搜
int n, k;
Node que[2*N];//队列 
int head, tail;//队列头、尾 
bool vis[N+5];
//试着将x位置添加进队列 
void tryAddToQue(int x, int t)
{
    if(x >= 0 && x <= N && vis[x] == false)
    {
        vis[x] = true;
        que[++tail] = Node(x, t);
    }
}

//返回抓到牛需要用的最小时间
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
        tryAddToQue(x + 1, t);//分别尝试去三个可能达到的位置 
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
