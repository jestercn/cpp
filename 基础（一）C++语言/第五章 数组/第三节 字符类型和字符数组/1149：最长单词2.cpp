#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[505], word[505], mxWord[505];
	cin.get(s, 505);
	int ct = 0, ctMax = 0, wi = 0;//ct:��������ĸ���� ctMax:��󵥴ʳ��� word_sp:����ʿ�ʼ��λ�� 
	for(int i = 0;i < strlen(s); ++i)
	{
		if(s[i] == ' ' || s[i] == '.')
		{
			word[wi] = '\0';
			wi = 0;
			if(ct > ctMax)
			{
				ctMax = ct;
				strcpy(mxWord, word);
			}
			ct = 0;
		}
		else
		{
			ct++;
			word[wi++] = s[i];
		}
	}
	cout<<mxWord;
	return 0;
}
