#include <bits/stdc++.h>
using namespace std;
//˼·���Ȱ�̺����Ϣ���������У��ٵõ�Ҫ�鿴�ĵ㣬����̺����Ϣ�����ĸ�̺�Ӹ�ס������㡣 
typedef struct Carpet
{
	int xmin, xmax, ymin, ymax;
	Carpet()
	{
		set(0,0,0,0);
	}
	void set(int a, int b, int g, int k)
	{
		xmin = a;
		xmax = a + g;
		ymin = b;
		ymax = b + k;
	}
	bool contains(int x, int y)//��̺�Ƿ��ס(x,y)��
	{
		if(x >= xmin && x <= xmax && y >= ymin && y <= ymax)
			return true;
		else
			return false;
	}
}Carpet;

int main()
{
	int n, a, b, g, k, x, y, frontCptNum = -1;//frontCptNum:������̺�ӵı�� 
	Carpet carp[10005];
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a>>b>>g>>k;
		carp[i].set(a, b, g, k);
	}
	cin>>x>>y;
	for(int i = 1; i <= n; ++i)
	{
		if(carp[i].contains(x, y))
			frontCptNum = i; 
	}	
	cout<<frontCptNum;
	return 0;
}
