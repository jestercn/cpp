#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, a, f = 0;//a��ÿ����ȡҩ���� f��δ�ɹ�ȡҩ���� 
	cin>>m>>n;
	int r = m;//ʣ���ҩƷ���� 
	for(int i = 0; i < n; ++i)
	{
		cin>>a;
		if(r < a)//���ʣ���ҩƷ����Ҫȡ��ҩ������ 
			f++;
		else
			r -= a;
	} 
	cout<<f;
	return 0;
}
