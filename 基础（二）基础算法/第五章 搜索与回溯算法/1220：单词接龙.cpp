#include<bits/stdc++.h>
using namespace std;
//单词排成一列，每个单词都对应一个下标，指向当前要看哪个字母
//遍历当前在看的单词w，所有单词的下标都跟随变化。若单词列表中某单词的下标指向的字母与单词w当期看的字母相同，那么下标加1，否则，下标重置为0.
//遍历完单词w的所有字母后，单词列表中下标不为0的单词，即为可能成为接着单词w的下一个单词 
char word[25][25];//word[i]表示第i个单词(从0数） 
int vis[25], n, ct, ctMax;//vis[i]表示第i个单词已经在龙中出现过几次 n:单词数 ct：龙长度计数 ctMax:长度最大值 
//wsel现在在遍历哪个单词  starti现在在看单词第几个字母（从0开始算）
//表示把第wsel单词加入龙中，并看下一个加入哪一个 
void Search(int wsel, int starti)
{
	int ind[25] = {};//各个单词的指向现在在看哪个字母的下标
	int len = strlen(word[wsel]); 
	for(int j = starti; j < len; ++j)//遍历第i单词的各个字符 
	{
		for(int i = 0;i < n; ++i)//遍历各个单词 
		{
			if(vis[i] < 2)//如果已经在龙中出现过2次，则不考虑 
			{
				if(word[i][ind[i]] == word[wsel][j])//如果单词列表第i单词第ind[i]字母与第wsel单词第i字母相同 
					ind[i]++;
				else
				{ 
					ind[i] = 0;//如果遇到不同的字母，那么从头开始检索
					if(word[i][ind[i]] == word[wsel][j])
						ind[i]++;	
				}
				if(ind[i] == strlen(word[i]))//如果ind[i]的位置已经在word[i]的'\0'的位置，也就是说当前单词word[wsel]完全包含了word[i]，那么word[i]不能用作接龙，ind[i]重置 
				{//前提：单词长度大于1.否则会出现问题。该问题中出现长度为1的单词无法和任何单词接龙，没有意义。 
					ind[i] = 0;//如果遇到不同的字母，那么从头开始检索
					if(word[i][ind[i]] == word[wsel][j])
						ind[i]++;
				}
			}
		} 
	}
	for(int i = 0; i < n; ++i)//对于第i个单词，若ind[i]>0，那么第i单词和第wsel单词有重合。下面使重合的区域最短，以使接龙后的单词最长 
	{
		for(int j = 0; j <= ind[i] - 2; ++j)//看看word[i]前j+1个字符和word[wsel]后j+1个字符是否相等 
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
	int charAdd = len - starti;//从starti遍历到 strlen(word[wsel])-1一共有 strlen(word[wsel]) - starti个字符 
	ct += charAdd;
	if(ct > ctMax)//更新最大值 
		ctMax = ct;
	for(int i = 0;i < n; ++i)
	{
		if(vis[i] < 2 && ind[i] > 0)//如果单词i有部分和单词wsel重合 
		{
			vis[i]++;
			Search(i, ind[i]);
			vis[i]--; 
		}
	}
	ct -= charAdd;//返回前还原 
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
