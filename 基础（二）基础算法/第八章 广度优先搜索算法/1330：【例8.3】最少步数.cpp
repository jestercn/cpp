#include <bits/stdc++.h>
using namespace std;
typedef struct Pair
{
    int x, y;//x��y������
    Pair(){}
    Pair(int a, int b):x(a),y(b){}
}Pair;

typedef struct Node
{
    Pair pos;
    int step;//step���Ѿ����˼���
    Node(){}
    Node(Pair a, int b):pos(a),step(b){}
}Node;//������еĽ��

Pair dir[12] = {{-2,1},{-2,-1},{2,1},{2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{-2,-2},{-2,2},{2,-2},{2,2}};//����������ߵ������λ��
bool vis[105][105];

bool isInField(Pair pos)
{
    if(pos.x >= 1 && pos.x <= 100 && pos.y >= 1 && pos.y <= 100)
        return true;
    else
        return false;
}

//�������ٲ���
int bfs(Pair startP)
{
    Node que[10005];
    int head = 0, tail = 0;
    que[++tail] = Node(startP, 0);
    vis[startP.x][startP.y] = true;
    while(head != tail)
    {
        Node selN = que[++head];
        for(int i = 0; i < 12; ++i)
        {
            Pair nextP(selN.pos.x + dir[i].x, selN.pos.y + dir[i].y);
            if(isInField(nextP) && vis[nextP.x][nextP.y] == false)
            {
                if(nextP.x == 1 && nextP.y == 1)//������յ�
                    return selN.step + 1;
                vis[nextP.x][nextP.y] = true;
                que[++tail] = Node(nextP, selN.step + 1);
            }
        }
    }
}

int main()
{
    Pair posA, posB;
    cin>>posA.x>>posA.y;
    cin>>posB.x>>posB.y;
    cout<<bfs(posA)<<endl;
    memset(vis, 0, sizeof(vis));
    cout<<bfs(posB)<<endl;
    return 0;
}
