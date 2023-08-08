#include<bits/stdc++.h>
using namespace std;
bool isPatient(double temperature, bool isCough)
{
	if(temperature >= 37.5 && isCough)
		return true;
	else
		return false;
}

int main()
{
	double temperature;
	bool isCough;
    int n, ct = 0;
    char name[100];
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
    	cin>>name>>temperature>>isCough;
    	if(isPatient(temperature, isCough))
    	{
    		cout<<name<<endl;
    		ct++;
    	}
	}
	cout<<ct;
    return 0;
}

