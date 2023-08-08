#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[105], words[200][100], c, o_str[105], n_str[105];
	int w_i = 0;
	do
	{
		cin>>words[w_i++];
		c = cin.get();
	}while(c != '\n');
	cin>>o_str>>n_str;
	for(int i = 0; i < w_i; ++i)
	{
		if(strcmp(words[i], o_str) == 0)
		{
			strcpy(words[i], n_str);
		}
	}
	for(int i = 0; i < w_i; ++i)
		cout<<words[i]<<' ';
	return 0;
}
