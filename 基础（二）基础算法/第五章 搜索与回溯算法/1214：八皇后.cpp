#include <bits/stdc++.h>
using namespace std;
//八皇后问题
//每行必然只有1个皇后 
//分别摆放第1行的皇后，第2行的皇后...第8行的皇后 
int pos[10];//pos[i]表示第i行的皇后放在哪一列
int qStr[100];//皇后串数组，qStr[i]表示第i个皇后串，每个皇后串是一个8位数字 
int qi = 1;//皇后串数组待存放位置 

//将当前pos[1]~pos[8]构成一个8位数字存入qStr[p] 
void setQStr(int p)
{
	int num = 0;
	for(int i = 1; i <= 8; ++i)
		num = num * 10 + pos[i];
	qStr[p] = num;
}

//第x,y位置是否可以放皇后，考虑第1~第x-1行存在皇后 
bool isOk(int x, int y)
{
	for(int i = 1; i <= x - 1;++i)//判断x,y正上方是否有皇后
	{
		if(pos[i] == y)//如果某一行第y列有皇后 
			return false;//那么位置x,y不能放皇后 
	} 
	for(int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--)//判断x,y左上方斜线上是否有皇后 
	{
		if(pos[i] == j) 
			return false;
	}
	for(int i = x - 1, j = y + 1; i >= 1 && j <= 8; i--, j++)//判断x,y右上方斜线上是否有皇后 
	{
		if(pos[i] == j) 
			return false;
	}
	return true;//如果上，左上，右上三个方向都没有皇后，那么此处可以放皇后 
}

//设置第r行皇后的位置 
void setQueen(int r)
{
	for(int i = 1; i <= 8; ++i)
	{
		if(isOk(r, i))
		{
			pos[r] = i;
			if(r == 8)//如果已经放完8个皇后，则设置皇后串 
				setQStr(qi++); 
			else
				setQueen(r + 1);//否则放下一行的皇后 
		}
	}
}

int main()
{   
	int n, x;
	cin>>n;
	setQueen(1);
	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		cout<<qStr[x]<<endl; 
	}
    return 0;
}
