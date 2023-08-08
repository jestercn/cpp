#include <bits/stdc++.h>
using namespace std;
//广搜问题 
//思路：先让初始楼层入队，每个楼层出队时，让从该楼层可能达到的楼层入队，记录楼层是否已访问过。
//直到到达目标楼层，或队空（无法达到目标楼层），则结束搜索 
typedef struct Data
{
    int s;//第几层 
    int t;//已经按了几次
    Data(int _s, int _t)
    {
        s = _s;
        t = _t;
    }
    Data()
    {
        Data(0, 0);
    }
}Data; 
int K[205];
Data que[2000];
int head, tail;
bool visited[205];
int main()
{
    int n, a, b, count = 0;
    Data d;
    cin>>n>>a>>b;
    for(int i = 1; i <= n; ++i)
        cin>>K[i];
    que[++tail] = Data(a, 0);//入队
    visited[a] = true; 
    while(head != tail)//队不为空 
    {
        d = que[++head];//s:临时取到的楼层
        visited[d.s] = true;
        if(d.s == b)//如果达到目标楼层 
        {
            cout<<d.t;
            return 0;
        } 
        if(d.s + K[d.s] <= n && visited[d.s + K[d.s]] == false)//向上按按钮要到的楼层存在，且没去过 
            que[++tail] = Data(d.s + K[d.s], d.t + 1);//入队 
        if(d.s - K[d.s] >= 1 && visited[d.s - K[d.s]] == false)//向下按按钮要到的楼层存在，且没去过
            que[++tail] = Data(d.s - K[d.s], d.t + 1);//入队  
    }
    cout<<-1;
	return 0;
}
