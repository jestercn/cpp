#include<bits/stdc++.h>
using namespace std;

//���n�ĵ����� 
void rev(int n)
{
	if(n == 0)
		return;
	cout<<n % 10;
	rev(n/10);
}

int main()
{
	int n;
	cin>>n;
	rev(n);
	return 0;
}
