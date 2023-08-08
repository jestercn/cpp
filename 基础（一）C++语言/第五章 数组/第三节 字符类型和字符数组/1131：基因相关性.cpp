#include<bits/stdc++.h>
using namespace std;

int main()
{
	double y;//y:ãÐÖµ ct:¼ÆÊý 
	char s1[505], s2[505];
	cin>>y>>s1>>s2;
	int len = strlen(s1), ct = 0;
	for(int i = 0; i < len; ++i)
	{
		if(s1[i] == s2[i])
			ct++;
	}
	if((double)ct / len >= y)
		cout<<"yes";
	else
		cout<<"no";
}
