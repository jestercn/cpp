#include <bits/stdc++.h>
using namespace std;
//fabs(x) �󸡵�����x�ľ���ֵ 
int main()
{
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<fixed<<setprecision(2)<<fabs((x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)/2);//��֪�����������������ʽ���������ģ�����ԭ���������ѯ 
	return 0;
}

