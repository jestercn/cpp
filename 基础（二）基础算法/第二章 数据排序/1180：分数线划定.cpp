#include<bits/stdc++.h>
using namespace std;
//�����ѵ���������� 
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
	for(int i = 0; i < n; ++i)//ѡ������
	{
		for(int j = i+1; j<n; ++j)
		{
			if(d[j].score > d[i].score || d[j].score == d[i].score && d[j].id < d[i].id)//�����Ҫ������С������ǰ�� 
			{
				temp = d[j];
				d[j] = d[i];
				d[i] = temp;
			}
		}
	}
	int selScore = d[(int)floor(m*1.5)-1].score;//������ 
	int selCount = 0;//��ѡ���� 
	for(int i = 0;d[i].score >= selScore; ++i)//ͳ����ѡ���� 
		selCount++;
	cout<<selScore<<' '<<selCount<<endl;
	for(int i = 0; i < selCount; ++i)
	{
		cout<<d[i].id<<' '<<d[i].score<<endl;
	}
    return 0;
}
