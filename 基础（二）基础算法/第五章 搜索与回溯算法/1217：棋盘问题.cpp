#include <bits/stdc++.h>
using namespace std;
char mp[10][10];
bool oc_l[10], oc_c[10];//oc_l[i]��ʾ��i���Ƿ�ռ��  oc_c[i]��ʾ��i���Ƿ�ռ�� 
bool vis[10][10];
int n, k, ct;//ct���������� 

//remʣ��δ�ڷ������� 
//����˳��Ϊ����mp[0][0]~mp[0][n-1], mp[1][0]~mp[1][n-1],... 
//����ʱ��ֻ���������˳���У�mp[x][y]��������̸��ӷ�rem������ 
void Search(int rem, int x, int y)
{
	if(rem == 0)//�������Ӷ����꣬���ӷ����� 
	{
		ct++;
		return;
	}
	else
	{
		for(int i = x; i < n; ++i)//�ӵ�x�п�ʼ���� 
		{
			if(oc_l[i] == false)
			{
				int j;
				if(i == x)//ֻ�е�x�У��ӵ�y�У�����map[x][y]��ʼ����
					j = y;
				else
					j = 0;//���������У���map[][0]��ʼ���� 
				for(; j < n; ++j)
				{
					if(oc_c[j] == false && mp[i][j] == '#' && vis[i][j] == false)
					{
						oc_l[i] = oc_c[j] = true;//������һ���б�ռ��
						vis[i][j] = true; 
						Search(rem - 1, i, j);
						vis[i][j] = false; 
						oc_l[i] = oc_c[j] = false;//�������һ���е�ռ�� 
					}
				}
			}
		}
	}
}

int main()
{   
   	while(true)
   	{
		cin>>n>>k;
		if(n == -1 && k == -1)
			break;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin>>mp[i][j];
		memset(oc_l, 0, sizeof(oc_l));
		memset(oc_c, 0, sizeof(oc_c));
		memset(vis, 0, sizeof(vis));
		ct = 0;
		Search(k, 0, 0);
		cout<<ct<<endl;
	}
    return 0;
}
