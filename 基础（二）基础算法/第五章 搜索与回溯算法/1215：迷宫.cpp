#include <bits/stdc++.h>
using namespace std;

char mp[105][105];
int n, ha, la, hb, lb;//ha, la��������ʼ�㡣hb, lb������Ŀ�ĵء�n������� 


bool vis[105][105]; 
//��������ʼ����h, l
bool Search(int h, int l)
{
	bool r_u, r_d, r_l, r_r;//���������������Ľ��
	r_u = r_d = r_l = r_r = false; 
	if(h == hb && l == lb)
		return true;
	else//���������'.'�����Խ�����һ������ 
	{
		vis[h][l] = true;
		if(h > 0 && vis[h - 1][l] == false && mp[h - 1][l] == '.')//�������ط�û�б�����������ط���'.' 
			r_u = Search(h - 1, l);
		if(r_u) 
			return true;//�ҵ�һ���ܵ����������Ϳ���ֱ�ӷ����ˣ������û��Ҫ�����ˡ� 
		if(h < n - 1 && vis[h + 1][l] == false && mp[h + 1][l] == '.')
			r_d = Search(h + 1, l);
		if(r_d) 
			return true;
		if(l > 0 && vis[h][l - 1] == false && mp[h][l - 1] == '.')
			r_l = Search(h, l - 1);
		if(r_l)
			return true;
		if(l < n - 1 && vis[h][l + 1] == false && mp[h][l + 1] == '.')
			r_r = Search(h, l + 1);
		if(r_r)
			return true;
		return false;//��������ֻҪ��1������������Ŀ�ĵأ���ô����true�����򷵻�false�� 
	}
}
int main()
{   	
   	int k;
   	cin>>k;
   	for(int i = 0; i < k; ++i)
   	{
   		memset(vis, 0, sizeof(vis));//���vis���� 
   		cin>>n;
   		for(int l = 0; l < n; ++l)
   			for(int c = 0; c < n; ++c)
   			{
   				cin>>mp[l][c]; 
		   	}
		cin>>ha>>la>>hb>>lb;
		if(mp[ha][la] == '#' || mp[hb][lb] == '#')//��ǰ�ж������յ�Ϊ'#'���������Search()Ҳ������������������ʱ�� 
			cout<<"NO"<<endl;
		else
		{
			bool canReach = Search(ha, la);//�Ƿ���Ե��� 
			cout<<(canReach ? "YES" : "NO")<<endl;
		}
	}
    return 0;
}
