#include <bits/stdc++.h>
using namespace std;
//������ģ������� 
int main()
{
    bool a[10005];//���λ��i������a[i]����Ϊtrue�����򱣴�Ϊfalse
	int l, m, start, end, s = 0;
	cin>>l>>m;
	for(int i = 0; i <= l; ++i)//a[0]~a[m]����Ϊ���� 
		a[i] = true;
	for(int i = 0; i < m; ++i)
	{
		cin>>start>>end;
		for(int j = start; j <= end; ++j)//a[start]��a[end]��Ϊ���� 
			a[j] = false;
	}
	for(int i = 0; i <= l; ++i)
	{
		if(a[i])
			s++;
	}
	cout<<s;
    return 0;
}
