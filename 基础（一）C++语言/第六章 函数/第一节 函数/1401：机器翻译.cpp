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
		word++;//word�ǷǸ����������䷶Χ��Ϊ������ 
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
