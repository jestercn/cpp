#include <bits/stdc++.h>
using namespace std;
//n�����100��n�����У�ȡ2�����γɹ�ϵ��������C(2,n)�����ֵ��C(2,100) <=5000, ��k<=5000 
//˼·������ÿ���ˣ����������ӣ���ʱ��ͥ������1�����ϳ���ֱ���ӿգ��ͳ��ӵ����й�ϵ���˶���ӡ����ӵ��˵ĸ��������������ͥ�������� 
typedef struct
{
	int x;
	int y;
}Relation;
bool visited[105];
int que[105], head, tail;
int main()
{
	int n, k, maxFamily = 0, familyNum = 0;//maxFamily����ͥ���� familyNum��ͥ���� 
	Relation rel[5005];//���5000����ϵ 
	cin>>n>>k;
	for(int i = 0; i < k; ++i)//�����ϵ 
	{
		cin>>rel[i].x>>rel[i].y;
	}
	for(int i = 1; i <= n; ++i)//����ÿ���� 
	{
		if(visited[i] == false)
		{
			int count = 0;//��������
			familyNum++; 
			que[++tail] = i;//���
			visited[i] = true; 
			while(head!=tail)
			{
				int selMan = que[++head];//���� һ��ѡ�е��� 
				count++;//ÿ����һ���ˣ���ͥ����������1 
				for(int j = 0; j < k; ++j)//�������й�ϵ 
				{//�����й�ϵ����һ������� 
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
