#include<bits/stdc++.h>
using namespace std;
/*��(a^b)%7
����(a*b)%c = (a%c*b%c)%c
(a*b*c)%d = ((a*b)%d*c%d)%d = ((a%d*b%d)%d*c%d)%d =((a%d*b%d)%d*c%d%d)%d = (a%d*b%d*c%d)%d 
�ɴ�Ҳ���Ե��� (a^b)%7 = ((a%7)^b)%7 
Ҳ����˵��n������˶�7ȡģ�����Խ���˵���������ȡģ������ȡģ���������˺���ȡģ
����������ÿ��һ�κ����һ��ȡģ 
*/ 
int main()
{
	int a, b, s = 1;
	cin>>a>>b;
	a %= 7;
	for(int i = 0; i < b; ++i)
	{
		s = (s*a)%7;
	}
	//�����չ���s�� 
	switch(s)
	{
		case 0:
			cout<<"Sunday";
			break;
		case 1:
			cout<<"Monday";
			break;
		case 2:
			cout<<"Tuesday";
			break;
		case 3:
			cout<<"Wednesday";
			break;
		case 4:
			cout<<"Thursday";
			break;
		case 5:
			cout<<"Friday";
			break;
		case 6:
			cout<<"Saturday";
			break;
	}
	return 0;
}
