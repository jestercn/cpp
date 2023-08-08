#include <bits/stdc++.h>
using namespace std;
#define N 45
typedef struct Node//设置结点
{
    int x, y, s;
    Node(){}
    Node(int a, int b, int c):x(a), y(b), s(c){}
}Node;
int r, c;//行、列
char mp[N][N];
bool vis[N][N];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool isValid(int x, int y)
{
    return x >= 1 && x <= r && y >= 1 && y <= c;
}
//返回最短步数
int bfs()
{
    Node que[5000];
    int head = 0, tail = 0;
    Node st(1, 1, 1);
    vis[1][1] = true;
    que[++tail] = st;
    while(head != tail)
    {
        Node sel = que[++head];
        if(sel.x== r && sel.y == c)//到终点
            return sel.s;
        for(int i = 0; i < 4; ++i)
        {
            int x = sel.x + dir[i][0], y = sel.y + dir[i][1], s = sel.s + 1;
            if(isValid(x, y) && vis[x][y] == false && mp[x][y] == '.')
            {
                vis[x][y] = true;
                que[++tail] = Node(x, y, s);
            }
        }
    }
}

int main()
{
    cin>>r>>c;
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j)
            cin>>mp[i][j];
    cout<<bfs();
    return 0;
}
