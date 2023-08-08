#include<bits/stdc++.h>
using namespace std;
//本题难点在理解题意 
typedef struct Data
{
	int id;
	int score;
}Data;

int main()
{
   	int n, m;
   	cin>>n>>m;
   	Data d[5005], temp;
   	for(int i = 0; i < n; ++i)
   	{
		cin>>d[i].id>>d[i].score;
	}
	for(int i = 0; i < n; ++i)//选择排序
	{
		for(int j = i+1; j<n; ++j)
		{
			if(d[j].score > d[i].score || d[j].score == d[i].score && d[j].id < d[i].id)//输出中要求报名号小的排在前面 
			{
				temp = d[j];
				d[j] = d[i];
				d[i] = temp;
			}
		}
	}
	int selScore = d[(int)floor(m*1.5)-1].score;//分数线 
	int selCount = 0;//入选人数 
	for(int i = 0;d[i].score >= selScore; ++i)//统计入选人数 
		selCount++;
	cout<<selScore<<' '<<selCount<<endl;
	for(int i = 0; i < selCount; ++i)
	{
		cout<<d[i].id<<' '<<d[i].score<<endl;
	}
    return 0;
}
