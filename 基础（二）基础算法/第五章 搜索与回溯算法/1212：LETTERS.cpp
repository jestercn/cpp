#include <bits/stdc++.h>
using namespace std;
char m[30][30];//�ַ���ά���� 
bool vis[200]; //���ַ���c��vis[c]��ʾ�Ƿ񾭹��ַ�c 
int ct, r, s, ctMax;//ct�������Ѿ�������λ������ , ctMax�Ѿ�������λ�õ������� 
//�ӵ�x,yλ�ÿ�ʼ�������� 
void Search(int x, int y)
{
	if(vis[m[x][y]])//����˴���ĸ�Ѿ����� 
		return;
	else
	{
		vis[m[x][y]] = true;//�����Ѿ�����m[x][y]��һ�ַ� 
		ct++;//�����˵�x,yλ�ã��������� 
		if(ct > ctMax)//ctMax����Ϊ������ 
			ctMax = ct;
		if(x > 1)//������ǵ�һ�У����������λ�� 
			Search(x - 1, y);
		if(x < r)//����������һ�У����������λ�� 
			Search(x + 1, y);
		if(y > 1)//������ǵ�һ�У����������λ��
			Search(x, y - 1);
		if(y < s)//����������һ�У����������λ�� 
			Search(x, y + 1);
		ct--;//�������غ����������˻ر��ε���Search֮ǰ��λ�ã�������ԭ 
		vis[m[x][y]]= false;//������ĸ��״̬��ԭ 
	}
}

int main()
{   	
   	cin>>r>>s;
   	for(int i = 1; i <= r; ++i)
   		for(int j = 1; j<= s; ++j)
   			cin>>m[i][j];
   	Search(1, 1);
	cout<<ctMax; 
    return 0;
}
