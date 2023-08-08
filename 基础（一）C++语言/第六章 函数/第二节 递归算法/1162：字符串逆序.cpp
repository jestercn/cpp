#include<bits/stdc++.h>
using namespace std;
void revChar()
{
	char c = cin.get();
	if(c == '!')
		return;
	revChar();
	cout<<c;
}

int main()
{
	revChar();
	return 0;
}
