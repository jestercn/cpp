#include <bits/stdc++.h>
using namespace std;
//�����ÿ���Ͽ���ʱ�䡣һ��7�죬7���Ͽ�ʱ��Ϊ7����������7���������ֵ 
int main()
{
	int a[10], inSch, outSch;
	for(int i = 1; i <= 7; ++i)
	{
		cin>>inSch>>outSch;
		a[i] = inSch + outSch;
	}
	int maxDay = 1;
	for(int i = 1; i <= 7; ++i)
	{
		if(a[i] > a[maxDay])
			maxDay = i;
	}
	if(a[maxDay] <= 8)//�����Ͽ�ʱ�䲻��8Сʱ�������ڲ����� 
		cout<<0;
	else
		cout<<maxDay;
	return 0;
}
