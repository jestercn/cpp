#include <bits/stdc++.h>
using namespace std;
//n最大是100，n个人中，取2个人形成关系，个数是C(2,n)，最大值是C(2,100) <=5000, 即k<=5000 
//思路：遍历每个人，这个人先入队，此时家庭数增加1，不断出队直到队空，和出队的人有关系的人都入队。出队的人的个数，就是这个家庭的人数。 
typedef struct
{
	int x;
	int y;
}Relation;
bool visited[105];
int que[105], head, tail;
int main()
{
	int n, k, maxFamily = 0, familyNum = 0;//maxFamily最大家庭人数 familyNum家庭个数 
	Relation rel[5005];//最多5000个关系 
	cin>>n>>k;
	for(int i = 0; i < k; ++i)//输入关系 
	{
		cin>>rel[i].x>>rel[i].y;
	}
	for(int i = 1; i <= n; ++i)//遍历每个人 
	{
		if(visited[i] == false)
		{
			int count = 0;//人数计数
			familyNum++; 
			que[++tail] = i;//入队
			visited[i] = true; 
			while(head!=tail)
			{
				int selMan = que[++head];//出队 一个选中的人 
				count++;//每出队一个人，家庭人数计数加1 
				for(int j = 0; j < k; ++j)//遍历所有关系 
				{//和他有关系的另一个人入队 
					if(rel[j].x == selMan && visited[rel[j].y] == false)
					{
						que[++tail] = rel[j].y;
						visited[rel[j].y] = true;
					}
					else if(rel[j].y == selMan && visited[rel[j].x] == false)
					{
						que[++tail] = rel[j].x;
						visited[rel[j].x] = true;
					}
				}
			}
			if(count > maxFamily)
				maxFamily = count;
		}
	}
	cout<<familyNum<<' '<<maxFamily;
}
