#include <bits/stdc++.h>
using namespace std;
//八皇后问题
//分析可知，该题给出的题解，实际上是按列放皇后得到的结果，先放第一列的皇后，再放第二列的皇后，。。。 
//其结果，是按行放皇后得到的棋盘矩阵的转置
 
int pos[10];//pos[i]表示第i列的皇后放在哪一行 
int mapNum = 1;
//num:序号 
void showMap(int num)
{
	cout<<"No. "<<num<<endl;
	for(int i = 1; i <= 8; ++i)
	{
		for(int j = 1; j <= 8; ++j)
		{
			if(pos[j] == i)
				cout<<"1 ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	} 
}

//第x,y位置是否可以放皇后，考虑第1~第y-1列存在的皇后 
bool isOk(int x, int y)
{
	for(int i = 1; i <= y - 1;++i)//判断x,y左侧是否有皇后
	{
		if(pos[i] == x)//如果第x行第i列有皇后 
			return false;//那么位置x,y不能放皇后 
	} 
	for(int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--)//判断x,y左上方斜线上是否有皇后 
	{
		if(pos[j] == i)//如果第i行第j列有皇后 
			return false;
	}
	for(int i = x + 1, j = y - 1; i <= 8 && j >= 1; i++, j--)//判断x,y左下方斜线上是否有皇后 
	{
		if(pos[j] == i)//如果第i行第j列有皇后 
			return false;
	}
	return true;//如果上，左上，右上三个方向都没有皇后，那么此处可以放皇后 
}
//设置第col列皇后的位置 
void setQueen(int col)
{
	for(int i = 1; i <= 8; ++i)//遍历8行 
	{
		if(isOk(i, col))//如果第i行第col列可以放皇后 
		{
			pos[col] = i;
			if(col == 8)//如果已经放完8个皇后，则输出棋盘 
				showMap(mapNum++); 
			else
				setQueen(col + 1);//否则放下一列的皇后 
		}
	}
}


int main()
{   
 	setQueen(1); 
    return 0;
}
