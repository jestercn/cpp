#include <bits/stdc++.h>
using namespace std;

int main()
{
	double xa, ya, xb, yb;
	cin>>xa>>ya>>xb>>yb;
	cout<<fixed<<setprecision(3)<<sqrt(pow(xa-xb,2) + pow(ya-yb,2));//������빫ʽ��������((xa-xb)��ƽ�� ���� (ya-yb)��ƽ��)
	//cmath�еĺ�����sqrt(x)����x�����ţ�pow(a,b)��a��b�η� 
	return 0;
}

