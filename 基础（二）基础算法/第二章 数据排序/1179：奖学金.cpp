#include<bits/stdc++.h>
using namespace std;
//���죺�ṹ�壬���ñȽϺ���
typedef struct Data
{
	int id;
	int Chinese;//���ĳɼ� 
	int score;//�ܳɼ� 
}Data;

bool isPrior(Data d1, Data d2)//�ȽϺ��� �ж�d1�Ƿ�Ӧ����d2ǰ��
{
	if(d1.score > d2.score)
		return true;
	else if(d1.score < d2.score)
		return false;
	else//�ܷ������ 
	{
		if(d1.Chinese > d2.Chinese)
			return true;
		else if(d1.Chinese < d2.Chinese)
			return false;
		else//���ĳɼ���� 
		{
			if(d1.id < d2.id)
				return true;
			else
				return false;
		}	
	}	
}

int main()
{
   	int n;
   	cin>>n;
   	int s1, s2, s3;//�������ģ���ѧ��Ӣ��ɼ�
	Data d[305], temp; 
   	for(int i = 0; i < n; ++i)
   	{
   		cin>>s1>>s2>>s3;
   		d[i].id = i+1;
   		d[i].Chinese = s1;
   		d[i].score = s1 + s2 + s3;
	}
	
	for(int i = 1; i < n; ++i)//�������� 
	{
		for(int j = i; j>0; --j)
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
	
	for(int i = 0; i < 5; ++i)
	{
		cout<<d[i].id<<' '<<d[i].score<<endl;
	}
    return 0;
}
