#include<bits/stdc++.h>
using namespace std;
/*��(a^b)%1000
����(a*b)%c = (a%c*b%c)%c
(a*b*c)%d = ((a*b)%d*c%d)%d = ((a%d*b%d)%d*c%d)%d;
�ɴ�Ҳ���Ե��� (a^b)%1000 = ((a%1000)^b)%1000 = ((a%1000 * a%1000)%1000 * (a%1000)^b-2)%1000 
Ҳ����˵��n������˶�1000ȡģ�����Խ���˵���������ȡģ������ȡģ���������˺���ȡģ
����������ÿ��һ�κ����һ��ȡģ 
*/ 
int main()
{
	int a, b, s = 1;
	cin>>a>>b;
	a %= 1000;
	for(int i = 0; i < b; ++i)
	{
		s = (s*a)%1000;
	}
	if(s<10)
		cout<<"00";
	else if (s < 100)
		cout<<'0';
	cout<<s;
	return 0;
}
