#include <bits/stdc++.h>
using namespace std;
char mp[25][25];
int l, c, ct;//ct:��ɫ��ש���� l������, c������
bool vis[25][25]; 
void Search(int x, int y)
{
	if(mp[x][y] == '#')
		return;
	else if(vis[x][y])
		return;
	else
	{	
		ct++;
		vis[x][y] = true;
		if(x > 0)
			Search(x - 1, y);
		if(x < l - 1)
			Search(x + 1, y);
		if(y > 0)
			Search(x, y - 1);
		if(y < c - 1)
			Search(x, y + 1);
	}
}

int main()
{   
	int sx, sy;//sx,sy��ʼλ�� 
   	while(true)
   	{
   		cin>>c>>l;//����w����������Ϊc��y����������Ϊl 
   		if(c == 0 && l == 0)//����һ���ж������������ʱ����ʾ���������
   			break;
   		for(int i = 0; i < l; ++i) 
   			for(int j = 0; j < c; ++j)
   			{
				cin>>mp[i][j];
				if(mp[i][j] == '@')
				{
					sx = i;
					sy = j;
				}
			}
		memset(vis, 0, sizeof(vis));
   		ct = 0;
		Search(sx, sy);
		cout<<ct<<endl;
	}
    return 0;
}
