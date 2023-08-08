#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k, a, s1 = 0, s5 = 0, s10 = 0;
	cin>>k;
	for(int i = 0; i < k; ++i)
	{
		cin>>a;
		if(a == 1)
			s1++;
		if(a == 5)
			s5++;
		if(a == 10)
			s10++;
	}
	cout<<s1<<endl;
	cout<<s5<<endl;
	cout<<s10<<endl;
}
