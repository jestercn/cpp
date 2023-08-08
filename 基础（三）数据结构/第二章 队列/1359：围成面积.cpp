#include <bits/stdc++.h>
using namespace std;
#define N 11
//广搜问题 
//思路：从外圈出发，进行广搜，把所有为0的地方设为已访问，剩下的就是1和圈内的位置
//接着从图中每个位置出发进行广搜，搜到0的位置的个数，即为圈内的位置的个数 
//表示位置的结构体 
typedef struct Pair
{
    int x;
    int y;
    Pair()
    {
        Pair(0,0); 
    }
    Pair(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    void set(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
}Pair;

bool visited[N][N];//初始值为false 
Pair que[10000];//队列 
int head, tail; 
int a[N][N];//地图 
//判断一个位置是否遍历过 
bool isVisited(Pair pos)
{
    return visited[pos.x][pos.y];
}
//获取地图上一个位置的值 
int getVal(Pair pos)
{
    return a[pos.x][pos.y];
}

//广搜遍历 把遍历到的位置的visited设为true
//返回遍历到的位置的数量 
int bfs(Pair pos)
{
    int count = 0;
    if(isVisited(pos) == false && getVal(pos) == 0)
    {
        que[++tail] = pos;//入队 
        while(head != tail)
        {
            Pair tpos = que[++head];//出队 
            if(isVisited(tpos) == false)
            {
                visited[tpos.x][tpos.y] = true;
                count++; 
                Pair npos[4];
                npos[0].set(tpos.x-1, tpos.y);
                npos[1].set(tpos.x+1, tpos.y);
                npos[2].set(tpos.x, tpos.y-1);
                npos[3].set(tpos.x, tpos.y+1);
                for(int i = 0; i < 4; ++i)//把上下左右的位置入队，条件：没遍历过，值为0，不出界 
                {
                    if(isVisited(npos[i]) == false && getVal(npos[i]) == 0 && npos[i].x >= 1 && npos[i].x <= 10 && npos[i].y >= 1 && npos[i].y <= 10)    
                        que[++tail] = npos[i];
                }
            }
        }
    }
    return count; 
}

int main()
{
    for(int i = 1; i <= 10; ++i)
        for(int j = 1; j <= 10; ++j)
        {
            cin>>a[i][j]; 
        }
    for(int i = 1; i <= 10; ++i)//从外圈点出发，进行广搜，把所有为0的地方都设为已访问 
    {
        bfs(Pair(i,1));
        bfs(Pair(i,10));
        bfs(Pair(1,i));
        bfs(Pair(10,i));
    }
    int count = 0;
    for(int i = 1; i <= 10; ++i)
        for(int j = 1; j <= 10; ++j)
        {
            count += bfs(Pair(i, j));
        }
    cout<<count;
	return 0;
}
