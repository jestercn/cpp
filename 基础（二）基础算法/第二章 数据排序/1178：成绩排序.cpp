#include<bits/stdc++.h>
using namespace std;
//����ʹ�ñȽϺ������Ƚ������� 
typedef struct Data
{
	char name[21];
	int score;
}Data;

//�ȽϺ��������d1Ӧ����d2ǰ�� ����true�����d2Ӧ����d1ǰ�棬����false 
bool isPrior(Data d1, Data d2)
{
	if(d1.score > d2.score)
		return true;
	else if(d1.score < d2.score)
		return false;
	else//������ȣ��Ƚ����� 
	{
		if(strcmp(d1.name, d2.name) < 0)//d1.name���ֵ����d2.nameС
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
	
	for(int i = 1; i < n; ++i)//�������� 
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
