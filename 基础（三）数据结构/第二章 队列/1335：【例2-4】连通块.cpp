#include<bits/stdc++.h>
using namespace std;
//广搜问题 
typedef struct Pair//定义类型，表示坐标 
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

int main()
{
  	int m, n, a[105][105], num = 0;//num：连通块个数 
  	memset(a, 0, sizeof(a));//初值为0 
  	bool isPas[105][105];//该位置是否遍历过，初值都设为false 
  	memset(isPas, false, sizeof(isPas));
	Pair que[10005];//队列 
	int tail = 0, head = 0;
	cin>>n>>m;
  	for(int i = 1; i <= n; ++i)
  		for(int j = 1; j <= m; ++j)
  		{
  			cin>>a[i][j];
     	}
    for(int i = 1; i <= n; ++i)
  		for(int j = 1; j <= m; ++j)
  		{
  			if(isPas[i][j] == false)//如果此处没有遍历过 
  			{
  				isPas[i][j] = true;
  				if(a[i][j] == 1)
  				{
  					num++;//每进入此处，表明有一个新的连通块 
  					Pair cord(i, j);
  					que[++tail] = cord;//入队 
  					while(head!=tail)//如果队不空 
  					{
  						cord = que[++head];//出队
						Pair tmpCord[4];//上下左右4个待探查的位置 
						tmpCord[0].set(cord.x-1, cord.y);
						tmpCord[1].set(cord.x+1, cord.y);
						tmpCord[2].set(cord.x, cord.y-1);
						tmpCord[3].set(cord.x, cord.y+1);
						for(int k = 0; k < 4; ++k)
						{
							//如果此处没被遍历过，且值是1 
							if(isPas[tmpCord[k].x][tmpCord[k].y] == false && a[tmpCord[k].x][tmpCord[k].y] == 1)
  							{
								que[++tail] = tmpCord[k];
								isPas[tmpCord[k].x][tmpCord[k].y] = true;
							}
						}
					}
  				}
			}
		}
	cout<<num; 
    return 0;
}
