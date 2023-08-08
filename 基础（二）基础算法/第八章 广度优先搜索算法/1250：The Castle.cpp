#include <bits/stdc++.h>
using namespace std;
typedef struct Pair
{
    int x, y;
    Pair(){}
    Pair(int a, int b):x(a), y(b){}
}Pair;
typedef struct Square
{
    bool wall[4];//wall[0]西，wall[1]北，wall[2]东，wall[3]南是否有墙
    Square(){}
    Square(int numP)
    {
        for(int i = 0; i < 4; ++i)
        {
            wall[i] = numP % 2;
            numP /= 2;
        }
    }
}Square;
int dir[4][2] = {{0,-1},{-1,0},{0,1},{1, 0}};//按照向西、北、东、南的顺序排列
int m, n, roomCt, squareCtMx;//roomCt：房间计数 squareCtMx:房间格子最大数
Square mp[51][51];
bool vis[51][51];
Pair que[5000];
int head, tail;

bool isValid(Pair p)
{
    return p.x >= 1 && p.x <= m && p.y >= 1 && p.y <= n;
}
void bfs(Pair st)
{
    if(vis[st.x][st.y])
        return;
    int squareCt = 0;//房间内格子计数
    roomCt++;
    head = tail = 0;
    vis[st.x][st.y] = true;
    squareCt++;
    que[++tail] = st;
    while(head != tail)
    {
        Pair pSel = que[++head];
        for(int i = 0; i < 4; ++i)
        {
            if(mp[pSel.x][pSel.y].wall[i] == false)//mp[pSel.x][pSel.y].wall[i]:pSel点在第i方向上是否有墙
            {
                Pair pNew(pSel.x + dir[i][0], pSel.y + dir[i][1]);
                if(isValid(pNew) && vis[pNew.x][pNew.y] == false)
                {
                    vis[pNew.x][pNew.y] = true;
                    squareCt++;
                    que[++tail] = pNew;
                }
            }
        }
    }
    if(squareCt > squareCtMx)
        squareCtMx = squareCt;
}

int main()
{
    int numP;
    cin>>m>>n;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin>>numP;
            mp[i][j] = Square(numP);
        }
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            bfs(Pair(i, j));
    cout<<roomCt<<endl;
    cout<<squareCtMx<<endl;
    return 0;
}
