#include<bits/stdc++.h>
using namespace std;
//�����ų�һ�У�ÿ�����ʶ���Ӧһ���±ָ꣬��ǰҪ���ĸ���ĸ
//������ǰ�ڿ��ĵ���w�����е��ʵ��±궼����仯���������б���ĳ���ʵ��±�ָ�����ĸ�뵥��w���ڿ�����ĸ��ͬ����ô�±��1�������±�����Ϊ0.
//�����굥��w��������ĸ�󣬵����б����±겻Ϊ0�ĵ��ʣ���Ϊ���ܳ�Ϊ���ŵ���w����һ������ 
char word[25][25];//word[i]��ʾ��i������(��0���� 
int vis[25], n, ct, ctMax;//vis[i]��ʾ��i�������Ѿ������г��ֹ����� n:������ ct�������ȼ��� ctMax:�������ֵ 
//wsel�����ڱ����ĸ�����  starti�����ڿ����ʵڼ�����ĸ����0��ʼ�㣩
//��ʾ�ѵ�wsel���ʼ������У�������һ��������һ�� 
void Search(int wsel, int starti)
{
	int ind[25] = {};//�������ʵ�ָ�������ڿ��ĸ���ĸ���±�
	int len = strlen(word[wsel]); 
	for(int j = starti; j < len; ++j)//������i���ʵĸ����ַ� 
	{
		for(int i = 0;i < n; ++i)//������������ 
		{
			if(vis[i] < 2)//����Ѿ������г��ֹ�2�Σ��򲻿��� 
			{
				if(word[i][ind[i]] == word[wsel][j])//��������б��i���ʵ�ind[i]��ĸ���wsel���ʵ�i��ĸ��ͬ 
					ind[i]++;
				else
				{ 
					ind[i] = 0;//���������ͬ����ĸ����ô��ͷ��ʼ����
					if(word[i][ind[i]] == word[wsel][j])
						ind[i]++;	
				}
				if(ind[i] == strlen(word[i]))//���ind[i]��λ���Ѿ���word[i]��'\0'��λ�ã�Ҳ����˵��ǰ����word[wsel]��ȫ������word[i]����ôword[i]��������������ind[i]���� 
				{//ǰ�᣺���ʳ��ȴ���1.�����������⡣�������г��ֳ���Ϊ1�ĵ����޷����κε��ʽ�����û�����塣 
					ind[i] = 0;//���������ͬ����ĸ����ô��ͷ��ʼ����
					if(word[i][ind[i]] == word[wsel][j])
						ind[i]++;
				}
			}
		} 
	}
	for(int i = 0; i < n; ++i)//���ڵ�i�����ʣ���ind[i]>0����ô��i���ʺ͵�wsel�������غϡ�����ʹ�غϵ�������̣���ʹ������ĵ���� 
	{
		for(int j = 0; j <= ind[i] - 2; ++j)//����word[i]ǰj+1���ַ���word[wsel]��j+1���ַ��Ƿ���� 
		{
			int k = j, l = 0;
			bool isSame = true; 
			while(k >= 0)
			{
				if(word[i][k] == word[wsel][len - 1 - l])
				{
					k--;
					l++;
				}
				else
				{
					isSame = false;
					break;
				}
			}
			if(isSame)
			{
				ind[i] = j + 1;
				break;
			}				
		}
	}
	int charAdd = len - starti;//��starti������ strlen(word[wsel])-1һ���� strlen(word[wsel]) - starti���ַ� 
	ct += charAdd;
	if(ct > ctMax)//�������ֵ 
		ctMax = ct;
	for(int i = 0;i < n; ++i)
	{
		if(vis[i] < 2 && ind[i] > 0)//�������i�в��ֺ͵���wsel�غ� 
		{
			vis[i]++;
			Search(i, ind[i]);
			vis[i]--; 
		}
	}
	ct -= charAdd;//����ǰ��ԭ 
}
int main()
{
    char beginChar;
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
    	cin>>word[i]; 
	}
	cin>>beginChar;
	for(int i = 0; i < n; ++i)
	{
		if(word[i][0] == beginChar)
		{
			vis[i]++;
			ct++;
			Search(i, 1);
			ct--;
			vis[i]--;
		}
	}
	cout<<ctMax;
	return 0;
} 
