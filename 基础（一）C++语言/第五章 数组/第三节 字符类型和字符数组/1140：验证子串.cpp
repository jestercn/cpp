#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    char s1[205], s2[205], temp[205];
    cin>>s1>>s2;
    if(strlen(s1) < strlen(s2))
    {
    	strcpy(temp, s1);
    	strcpy(s1, s2);
    	strcpy(s2, temp);
	}//����s1�ĳ��ȴ��ڵ���s2�ĳ��� 
	int j = 0;
	for(int i = 0; i < strlen(s1); ++i)
	{
		if(s1[i] == s2[j])
		{
			j++;
			if(j == strlen(s2))//j�Ѿ�ָ��s2��'\0'����ôs2���Ӵ� 
			{
				 cout<<s2<<" is substring of "<<s1;
				 return 0;				
			}
		}
		else
			j = 0;
	}
	cout<<"No substring";
} 
