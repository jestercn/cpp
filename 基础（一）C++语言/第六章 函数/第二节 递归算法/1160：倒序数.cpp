#include<bits/stdc++.h>
using namespace std;

//Êä³önµÄµ¹ĞòÊı 
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
