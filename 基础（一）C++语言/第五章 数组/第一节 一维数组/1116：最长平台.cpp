#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, len = 1, maxLen = 0, lastNum, num;//len:ƽ̨���� maxLen:���ƽ̨���� lastNum:��һ���� 
	cin>>n;
	cin>>lastNum;
	for(int i = 1; i < n; ++i)
	{
		cin>>num;
		if(num == lastNum)
		{
			len++;
			if(len > maxLen)
				maxLen = len;
		}
		else
		{
			lastNum = num;
			len = 1;
		}
	}
	cout<<maxLen;
	return 0;
}
