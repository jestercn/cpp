#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, r;
	const double PI = 3.14159;
	cin>>h>>r;
	cout<< ceil(20/(PI*r*r*h/1000));//PI*r*r*h��Բ����� ��λ�������ף�����������1000�󣬵�λΪ����
	//ceil()������ȡ��������20/Բ���������ֵ����ȡ������Ϊ���ٺȼ�Ͱˮ���ȵ���ˮ�Ŵ��ڵ���20���������ܽ�� 
	return 0;
}

