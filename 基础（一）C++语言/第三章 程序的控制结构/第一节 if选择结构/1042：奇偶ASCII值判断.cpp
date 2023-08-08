#include<bits/stdc++.h>
using namespace std;
//char类型的量，既可以当做字符，又可以当做数字。当做数字时，它的值就是它的ASCII码 
int main()
{
	char c;
	cin>>c;
	if(c%2 == 1)
		cout<<"YES";
	else
		cout<<"NO";		 
	return 0;
}
