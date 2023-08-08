//桶排序
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int buk[700];
int getNum(int p, int w)
{
	int pos = max(1, p * w / 100);//要找第pos位的成绩
	for(int i = 600; i >= 0; --i)//从高分看到低分
	{
		pos -= buk[i];//位数减去这个分数的人数
		if(pos <= 0)//如果位数减到0了，说明这一分数就是分数线
			return i;
	}
}

int main()
{
	int n, w, g, i, line;//line:分数线
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &g);
		buk[g]++;
		printf("%d ", getNum(i, w));
	}
	return 0;
}
