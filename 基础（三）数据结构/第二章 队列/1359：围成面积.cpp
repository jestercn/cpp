#include <bits/stdc++.h>
using namespace std;
#define N 11
//�������� 
//˼·������Ȧ���������й��ѣ�������Ϊ0�ĵط���Ϊ�ѷ��ʣ�ʣ�µľ���1��Ȧ�ڵ�λ��
//���Ŵ�ͼ��ÿ��λ�ó������й��ѣ��ѵ�0��λ�õĸ�������ΪȦ�ڵ�λ�õĸ��� 
//��ʾλ�õĽṹ�� 
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

bool visited[N][N];//��ʼֵΪfalse 
Pair que[10000];//���� 
int head, tail; 
int a[N][N];//��ͼ 
//�ж�һ��λ���Ƿ������ 
bool isVisited(Pair pos)
{
    return visited[pos.x][pos.y];
}
//��ȡ��ͼ��һ��λ�õ�ֵ 
int getVal(Pair pos)
{
    return a[pos.x][pos.y];
}

//���ѱ��� �ѱ�������λ�õ�visited��Ϊtrue
//���ر�������λ�õ����� 
int bfs(Pair pos)
{
    int count = 0;
    if(isVisited(pos) == false && getVal(pos) == 0)
    {
        que[++tail] = pos;//��� 
        while(head != tail)
        {
            Pair tpos = que[++head];//���� 
            if(isVisited(tpos) == false)
            {
                visited[tpos.x][tpos.y] = true;
                count++; 
                Pair npos[4];
                npos[0].set(tpos.x-1, tpos.y);
                npos[1].set(tpos.x+1, tpos.y);
                npos[2].set(tpos.x, tpos.y-1);
                npos[3].set(tpos.x, tpos.y+1);
                for(int i = 0; i < 4; ++i)//���������ҵ�λ����ӣ�������û��������ֵΪ0�������� 
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
    for(int i = 1; i <= 10; ++i)//����Ȧ����������й��ѣ�������Ϊ0�ĵط�����Ϊ�ѷ��� 
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
