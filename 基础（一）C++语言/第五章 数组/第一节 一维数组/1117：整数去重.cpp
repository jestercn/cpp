#include <bits/stdc++.h>
using namespace std;
//ɢ�д洢 
int main()
{
	bool isExist[5005] = {};
	int n, a[20005];
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	//������ֺ�,��isExist[a[i]]��Ϊtrue��������isExist[a[i]]Ϊtrue������� 
	for(int i = 0; i < n; ++i)
	{
		if(isExist[a[i]] == false)
		{
			cout<<a[i]<<' ';
			isExist[a[i]] = true;	
		}
	}
	return 0;
}
