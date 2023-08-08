#include<bits/stdc++.h>
using namespace std;
//如果把A~Z用0~25表示，那么 密文 = 明文 + 秘钥 
//所以有：明文 = 密文 - 秘钥 

int main()
{
	char s_k[105], s_c[1005], st_c;
	cin>>s_k;
	cin>>s_c;
	int n_k[105], len_k = strlen(s_k), n_c;
	for(int i = 0; i < len_k; ++i)
	{
		if(s_k[i] >= 'A' && s_k[i] <= 'Z')
			n_k[i] = s_k[i] - 'A';
		else
			n_k[i] = s_k[i] - 'a'; 
	}
	for(int i = 0; i < strlen(s_c); ++i)
	{
		if(s_c[i] >= 'A' && s_c[i] <= 'Z')
		{
			st_c = 'A';
			n_c = s_c[i] - 'A';
		}
		else
		{
			st_c = 'a';
			n_c = s_c[i] - 'a';
		}
		
		cout<<char((n_c + 26 - n_k[i % len_k]) % 26 + st_c); 
	}
	return 0;
}
