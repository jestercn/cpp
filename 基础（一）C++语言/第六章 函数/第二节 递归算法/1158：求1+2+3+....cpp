#include<bits/stdc++.h>
using namespace std;

//��1+2+...+n�ĺ� 
int sum(int n) 
{
	if(n == 1)
		return 1;
	else
		return n + sum(n - 1);	
}

int main()
{
	int n;
	cin>>n;
	cout<<sum(n);
	return 0;
}
