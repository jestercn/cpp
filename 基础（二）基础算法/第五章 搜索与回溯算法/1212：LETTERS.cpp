#include <bits/stdc++.h>
using namespace std;
char m[30][30];//字符二维数组 
bool vis[200]; //有字符量c，vis[c]表示是否经过字符c 
int ct, r, s, ctMax;//ct计数，已经经过的位置数量 , ctMax已经经过的位置的最大计数 
//从第x,y位置开始进行搜索 
void Search(int x, int y)
{
	if(vis[m[x][y]])//如果此处字母已经经过 
		return;
	else
	{
		vis[m[x][y]] = true;//设置已经经过m[x][y]这一字符 
		ct++;//经过了第x,y位置，计数增加 
		if(ct > ctMax)//ctMax保持为最大计数 
			ctMax = ct;
		if(x > 1)//如果不是第一行，搜索上面的位置 
			Search(x - 1, y);
		if(x < r)//如果不是最后一行，搜索下面的位置 
			Search(x + 1, y);
		if(y > 1)//如果不是第一列，搜索左面的位置
			Search(x, y - 1);
		if(y < s)//如果不是最后一列，搜索右面的位置 
			Search(x, y + 1);
		ct--;//函数返回后，搜索点会回退回本次调用Search之前的位置，计数还原 
		vis[m[x][y]]= false;//经过字母的状态还原 
	}
}

int main()
{   	
   	cin>>r>>s;
   	for(int i = 1; i <= r; ++i)
   		for(int j = 1; j<= s; ++j)
   			cin>>m[i][j];
   	Search(1, 1);
	cout<<ctMax; 
    return 0;
}
