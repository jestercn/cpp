#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, h, l, c = 0, cm = 0;//h:����ѹ��l������ѹ c:Ѫѹ���������Ĵ���  cm:Ѫѹ���������������� 
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>h>>l;
		if(h >= 90 && h <= 140 && l >= 60 && l <= 90)
		{ 
			c++;//�������������������Ѫѹ��������
			if(c > cm)
				cm = c;
		}
		else//���������������������Ѫѹ������Ϊ0 
			c = 0;
	}
	cout<<cm;
	return 0;
}
