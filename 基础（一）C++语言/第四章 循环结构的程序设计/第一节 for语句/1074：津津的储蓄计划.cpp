#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m = 0, s = 0, b;//m��������е�Ǯ s�����Ǯ, b��ĳ���µ�Ԥ�� 
	for(int i = 1; i <= 12; ++i)
	{
		cin>>b;
		if(m + 300 >= b)//����������õ�Ǯ���ڵ���Ԥ�� 
		{
			int t = m + 300 - b;//t��Ԥ�Ʊ���ĩʣ���Ǯ 
			m = t%100; //��Ǯ������ʣ���Ǯ 
			s += t - m; //��Ǯ 
		}
		else//����������õ�ǮС��Ԥ�� 
		{
			cout<<-i;
			return 0; 
		} 
	}
	cout<<s*1.2 + m;//���+��Ϣ+�����Ǯ 
}
