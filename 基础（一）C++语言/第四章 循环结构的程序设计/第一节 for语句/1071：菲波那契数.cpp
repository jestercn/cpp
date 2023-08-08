#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int k, n2 = 1, n1 = 1, temp;//n2,n1是当前求出的倒数第二项，和最后一项 
	cin>>k;
	for(int i = 3; i <= k; ++i)
	{
		temp = n1;
		n1 = n1 + n2;
		n2 = temp;
	}
	cout<<n1;
	return 0;
}
