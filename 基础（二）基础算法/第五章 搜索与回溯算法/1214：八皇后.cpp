#include <bits/stdc++.h>
using namespace std;
//�˻ʺ�����
//ÿ�б�Ȼֻ��1���ʺ� 
//�ֱ�ڷŵ�1�еĻʺ󣬵�2�еĻʺ�...��8�еĻʺ� 
int pos[10];//pos[i]��ʾ��i�еĻʺ������һ��
int qStr[100];//�ʺ����飬qStr[i]��ʾ��i���ʺ󴮣�ÿ���ʺ���һ��8λ���� 
int qi = 1;//�ʺ���������λ�� 

//����ǰpos[1]~pos[8]����һ��8λ���ִ���qStr[p] 
void setQStr(int p)
{
	int num = 0;
	for(int i = 1; i <= 8; ++i)
		num = num * 10 + pos[i];
	qStr[p] = num;
}

//��x,yλ���Ƿ���ԷŻʺ󣬿��ǵ�1~��x-1�д��ڻʺ� 
bool isOk(int x, int y)
{
	for(int i = 1; i <= x - 1;++i)//�ж�x,y���Ϸ��Ƿ��лʺ�
	{
		if(pos[i] == y)//���ĳһ�е�y���лʺ� 
			return false;//��ôλ��x,y���ܷŻʺ� 
	} 
	for(int i = x - 1, j = y - 1; i >= 1 && j >= 1; i--, j--)//�ж�x,y���Ϸ�б�����Ƿ��лʺ� 
	{
		if(pos[i] == j) 
			return false;
	}
	for(int i = x - 1, j = y + 1; i >= 1 && j <= 8; i--, j++)//�ж�x,y���Ϸ�б�����Ƿ��лʺ� 
	{
		if(pos[i] == j) 
			return false;
	}
	return true;//����ϣ����ϣ�������������û�лʺ���ô�˴����ԷŻʺ� 
}

//���õ�r�лʺ��λ�� 
void setQueen(int r)
{
	for(int i = 1; i <= 8; ++i)
	{
		if(isOk(r, i))
		{
			pos[r] = i;
			if(r == 8)//����Ѿ�����8���ʺ������ûʺ� 
				setQStr(qi++); 
			else
				setQueen(r + 1);//�������һ�еĻʺ� 
		}
	}
}

int main()
{   
	int n, x;
	cin>>n;
	setQueen(1);
	for(int i = 0; i < n; ++i)
	{
		cin>>x;
		cout<<qStr[x]<<endl; 
	}
    return 0;
}
