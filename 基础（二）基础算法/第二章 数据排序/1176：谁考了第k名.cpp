#include<bits/stdc++.h>
using namespace std;
//����ṹ�� ���� 
//���k����Ӧ�ý��н����������������дӴ�С 
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
	for(int i = 0; i < n-1; ++i)//ð������ 
		for(int j = 0; j < n-1-i; ++j)
		{
			if(d[j].score < d[j+1].score)
			{
				Data temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	printf("%d %g", d[k-1].num, d[k-1].score);//��k��ѧ�������ݴ���������d���±�Ϊk-1��λ�� 
	return 0;
}
