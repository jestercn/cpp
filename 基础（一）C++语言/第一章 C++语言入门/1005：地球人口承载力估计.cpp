#include <bits/stdc++.h>
using namespace std;

/*Сѧ��ѧӦ���� ��Ԫһ�η��������� 
�����ÿ��������ԴΪn,������ԴΪm, 1����ÿ��������Դp 
���з����飺 
x*p*a = m + a*n
y*p*b = m + b*n
ʹ��Դ���ݽߣ�ÿ�����ĵ���Դ����С�ڵ�����������Դ���� 
z*p <= n
��z <= n/p ���������������˿�����Ϊn/p 
���������߳���p���ã� 
x*a = m/p + a*n/p
y*b = m/p + b*n/p
������������ã� 
x*a - y*b = (a-b)n/p
n/p = (x*a - y*b)/(a-b)
*/ 
//����xλС����д����
//cout<<fixed<<setprecision(x)<<...
//printf("%.xd", ...); 
int main()
{
	int x,y,a,b;
	cin>>x>>a>>y>>b;
	//ֵΪ���͵ı��ʽ�����������������㡣����õ�ʵ����������������һ�����ʽ��ֵǿתΪ������ 
	cout<<fixed<<setprecision(2)<<(double)(x*a - y*b)/(a-b); 
	return 0;
}

