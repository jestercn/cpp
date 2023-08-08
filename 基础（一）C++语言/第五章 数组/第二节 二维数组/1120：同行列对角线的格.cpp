#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, sel_i, sel_j, a[15][15];//sel_i sel_j选中位置的横纵坐标 
	scanf("%d %d %d", &n, &sel_i, &sel_j);
	for(int j = 1; j <= n; ++j)
		printf("(%d,%d) ", sel_i, j);
	putchar('\n');
	for(int i = 1; i <= n; ++i)
		printf("(%d,%d) ", i, sel_j);
	putchar('\n');
	
	int f_i = sel_i, f_j = sel_j;//寻找与(i,j)在同一左上右下对角线上，左上方的第一个位置 
	while(f_i > 1 && f_j > 1)
	{//找左上方的格子 
		f_i--;
		f_j--;
	}
	//此时f_i,f_j就是对角线上左上角第一个位置
	for(int i = f_i, j = f_j; i <= n && j <= n; ++i, ++j)
	{
		printf("(%d,%d) ", i, j);
	}
	putchar('\n');
	
	f_i = sel_i, f_j = sel_j;//寻找与(i,j)在同一右上左下对角线上，左下方的第一个位置 
	while(f_i < n && f_j > 1) 
	{//找左下方的格子 
		f_i++;
		f_j--;
	}
	//此时f_i,f_j就是对角线上左下角第一个位置
	for(int i = f_i, j = f_j; i >= 1 && j <= n; --i, ++j)
	{
		printf("(%d,%d) ", i, j);
	}
	return 0;
}
