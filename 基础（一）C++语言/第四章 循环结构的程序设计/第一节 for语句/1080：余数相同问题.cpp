#include<bits/stdc++.h>
using namespace std;
//������ 
//��Ȼa,b,c��С�ڵ���10^6������Ŀ��֤x�н�
//��ô���Խ�x��2ѭ����10^6����Ѱ�ҿ��е�x 
int main()
{
	int x, a, b, c;
	cin>>a>>b>>c;
	int am, bm, cm;
	for(x = 2; x <= 1000000; ++x)
	{
		am = a % x;
		bm = b % x;
		cm = c % x;
		if(am == bm && bm == cm && cm == am)
		{
			cout<<x;//ֻ����Сֵ����ô�ҵ�һ������������x���� 
			break;
		}
	}
	return 0;
}
