#include<bits/stdc++.h>
using namespace std;
//���a>=b, a/b = (mb+ r)/b = m + r/b, ����r<b, ����mΪa/b(��������), rΪa%b 
//��С��λ����r/b�������
//����ģ�������ʽ�ļ������
//ÿ�α�����r�������10�����Գ���b��������һλС��������d��ʣ������r%b��Ϊ��һ�γ�����ı����� 
int main()
{
	int a, b, n;
	cin>>a>>b>>n;
	int r = a%b;
	int d;//dΪĳһλ��С�� 
	for(int i = 1; i <= n; ++i)
	{
		r *= 10;
		d = r/b;
		r %= b;
	} 
	cout<<d;
	return 0;
}
