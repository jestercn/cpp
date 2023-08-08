#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool hasWord[1005] = {}; 
	int mem[10000] = {}, mi = 0, ct = 0, m, n, word;
	cin>>m>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>word;
		word++;//word是非负整数，将其范围改为正整数 
		if(hasWord[word] == false)
		{
			hasWord[word] = true;
			if(mi + 1 == m)
				mi = 0;
			else
				mi++;
			if(mem[mi] > 0)
				hasWord[mem[mi]] = false;	
			mem[mi] = word;
			ct++;
		}
	}
	cout<<ct;
	return 0;
}
