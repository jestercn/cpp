#include<bits/stdc++.h>
using namespace std;
/*�������n��������������0��n������ͬ������n�����ĺ͵���Сֵ
��Ȼ������n����Ϊ1,2,3,...,nʱ������С��
�������ת��Ϊ��1+2+...+n�ĺ� 
*/
int main()
{
	int n, s = 0;
	cin>>n;
	for(int i = 1; i <= n; ++i)
		s += i;
	cout<<s;
	return 0;
}
