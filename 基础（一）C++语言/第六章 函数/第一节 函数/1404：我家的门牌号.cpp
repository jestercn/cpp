#include<bits/stdc++.h>
using namespace std;
//���Ҽ�����x���ܹ���y��
//�����г����̣�(1 + y)y/2 - x - 2*x = n  
//�������� 
int main()
{
	int n, s = 0;
	cin>>n;
	for(int y = 1; true ; ++y)
	{
		for(int x = 1; x <= y; ++x)
		{
			if((1+y)*y/2-3*x == n)
			{
				cout<<x<<' '<<y;
				return 0;		
			}
		}
	}
}
