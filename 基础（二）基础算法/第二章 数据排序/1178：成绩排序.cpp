#include<bits/stdc++.h>
using namespace std;
//考察使用比较函数来比较两个量 
typedef struct Data
{
	char name[21];
	int score;
}Data;

//比较函数，如果d1应该在d2前面 返回true，如果d2应该在d1前面，返回false 
bool isPrior(Data d1, Data d2)
{
	if(d1.score > d2.score)
		return true;
	else if(d1.score < d2.score)
		return false;
	else//分数相等，比较名字 
	{
		if(strcmp(d1.name, d2.name) < 0)//d1.name的字典序比d2.name小
			return true;
		else
			return false; 
	}
		
}
int main()
{
	int n;
	cin>>n;
	Data d[25], temp;
	for(int i = 0; i < n; ++i)
	{
		cin>>d[i].name>>d[i].score;
	}
	
	for(int i = 1; i < n; ++i)//插入排序 
	{
		for(int j = i; j > 0; --j)
		{
			if(isPrior(d[j], d[j-1]))
			{
				temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
			else
				break;
		}
	}
	for(int i = 0; i < n; ++i)
	{
		cout<<d[i].name<<' '<<d[i].score<<endl;
	}
	return 0;
}
