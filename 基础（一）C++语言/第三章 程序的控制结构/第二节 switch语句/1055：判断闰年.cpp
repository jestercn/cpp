#include<bits/stdc++.h>
using namespace std;
int main()
{
	int y;
	cin>>y;
	if(y%400 == 0 || y%100 != 0 && y%4 == 0)
		cout<<"Y";
	else
		cout<<"N";
	return 0;
} 
