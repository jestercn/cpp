#include<bits/stdc++.h>
using namespace std;
//����ֻ���������ѭ����Ҳ�����á������ݡ����㷨���� 
int main()
{
	int a, n, s = 1;
	cin>>a>>n;
	for(int i = 0; i < n; ++i)
	{
		s *= a;
	}
	cout<<s;
	return 0;
}
