#include <bits/stdc++.h>
using namespace std;
//�˻ʺ�����
//������֪�������������⣬ʵ�����ǰ��зŻʺ�õ��Ľ�����ȷŵ�һ�еĻʺ��ٷŵڶ��еĻʺ󣬡����� 
//�������ǰ��зŻʺ�õ������̾����ת��
 
int pos[10];//pos[i]��ʾ��i�еĻʺ������һ�� 
int mapNum = 1;
//num:��� 
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

//��x,yλ���Ƿ���ԷŻʺ󣬿��ǵ�1~��y-1�д��ڵĻʺ� 
bool isOk(int x, int y)
{
	for(int i = 1; i <= y - 1;++i)//�ж�x,y����Ƿ��лʺ�
	{
		if(pos[i] == x)//�����x�е�i���лʺ� 
			return false;//��ôλ��x,y���ܷŻʺ� 
	} 
	for(int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--)//�ж�x,y���Ϸ�б�����Ƿ��лʺ� 
	{
		if(pos[j] == i)//�����i�е�j���лʺ� 
			return false;
	}
	for(int i = x + 1, j = y - 1; i <= 8 && j >= 1; i++, j--)//�ж�x,y���·�б�����Ƿ��лʺ� 
	{
		if(pos[j] == i)//�����i�е�j���лʺ� 
			return false;
	}
	return true;//����ϣ����ϣ�������������û�лʺ���ô�˴����ԷŻʺ� 
}
//���õ�col�лʺ��λ�� 
void setQueen(int col)
{
	for(int i = 1; i <= 8; ++i)//����8�� 
	{
		if(isOk(i, col))//�����i�е�col�п��ԷŻʺ� 
		{
			pos[col] = i;
			if(col == 8)//����Ѿ�����8���ʺ���������� 
				showMap(mapNum++); 
			else
				setQueen(col + 1);//�������һ�еĻʺ� 
		}
	}
}


int main()
{   
 	setQueen(1); 
    return 0;
}
