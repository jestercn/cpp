#include<bits/stdc++.h>
using namespace std;
//�������� 
typedef struct Pair//�������ͣ���ʾ���� 
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
  	int m, n, a[105][105], num = 0;//num����ͨ����� 
  	memset(a, 0, sizeof(a));//��ֵΪ0 
  	bool isPas[105][105];//��λ���Ƿ����������ֵ����Ϊfalse 
  	memset(isPas, false, sizeof(isPas));
	Pair que[10005];//���� 
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
  			if(isPas[i][j] == false)//����˴�û�б����� 
  			{
  				isPas[i][j] = true;
  				if(a[i][j] == 1)
  				{
  					num++;//ÿ����˴���������һ���µ���ͨ�� 
  					Pair cord(i, j);
  					que[++tail] = cord;//��� 
  					while(head!=tail)//����Ӳ��� 
  					{
  						cord = que[++head];//����
						Pair tmpCord[4];//��������4����̽���λ�� 
						tmpCord[0].set(cord.x-1, cord.y);
						tmpCord[1].set(cord.x+1, cord.y);
						tmpCord[2].set(cord.x, cord.y-1);
						tmpCord[3].set(cord.x, cord.y+1);
						for(int k = 0; k < 4; ++k)
						{
							//����˴�û������������ֵ��1 
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
