#include <bits/stdc++.h>
using namespace std;

int main()
{
   	char s1[105], s2[105];
   	cin.get(s1, 105);
   	int len = strlen(s1);
   	for(int i = 0; i < len; ++i)
   	{
   		s2[i] = s1[i] + s1[(i + 1)%len];
	}
   	s2[len] = '\0';
   	cout<<s2;
    return 0;
}
