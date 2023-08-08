#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[260], s1[260];
	cin>>s;
	for(int i = 0; i < strlen(s); ++i)
	{
		switch(s[i])
		{
			case 'A':
				s1[i] = 'T';
				break;
			case 'T':
				s1[i] = 'A';
				break;
			case 'G':
				s1[i] = 'C';
				break;
			case 'C':
				s1[i] = 'G';
				break;
		}
	}
	s1[strlen(s)] = '\0';
	cout<<s1;
    return 0;
}
