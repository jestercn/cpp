#include<bits/stdc++.h>
using namespace std;
//考察结构体 排序 
//求第k名，应该进行降序排序，排序后的数列从大到小 
typedef struct Data
{
	int num;
	double score; 
}Data;

int main()
{
	int n, k;
	Data d[101];
	cin>>n>>k;
	for(int i = 0; i < n; ++i)
	{
		cin>>d[i].num>>d[i].score;
	}
	for(int i = 0; i < n-1; ++i)//冒泡排序 
		for(int j = 0; j < n-1-i; ++j)
		{
			if(d[j].score < d[j+1].score)
			{
				Data temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	printf("%d %g", d[k-1].num, d[k-1].score);//第k名学生的数据储存在数组d的下标为k-1的位置 
	return 0;
}
