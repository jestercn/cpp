#include<bits/stdc++.h>
using namespace std;
//假设，单独一个数字也算是组内互质的一组 
int n, num[15], ct, ctMin = INT_MAX;//ct:组计数 ctMin:最小组数
bool vis[15];//vis[i] == true 表示第i个数字已经分配到一个组中 
bool isHuzhi(int a, int b)
{
	for(int i = 2; i <= a; ++i)
	{
		if(b % i == 0 && a % i == 0)//若a，b存在大于1的公约数
			return false; 
	}
	return true;
}

//从num[n_i]能否加入当前组g中 
bool canEnterGroup(int g[], int g_n, int n_i)//g:一组数 g_n:数组g中数字个数 
{
	for(int i = 0; i < g_n; ++i)
	{
		if(isHuzhi(g[i], num[n_i]) == false)
			return false;
	}
	return true;	
}

//获取n_i后面的第一个 vis[i] == false的i
//若找到了，返回那个位置的下标，若未找到，返回n 
int getNextValidPos(int n_i)
{
	int i;
	for(i = n_i+1; i < n; ++i)
	{
		if(vis[i] == false)
			break;
	}
	return i;
}

//调用前保证vis[n_i] == false
//从num[n_i]开始向后搜索,形成一个组 
void Search(int n_i)
{
	int g[15], g_n = 0, ind[15], ind_n = 0;//g：数字组 g_n:g中元素个数 ind:g中保存了num中哪些下标的数字 
	for(int i = n_i; i < n; ++i)
	{
		if(vis[i] == false && canEnterGroup(g, g_n, i))
		{
			g[g_n++] = num[i];
			ind[ind_n++] = i;
			vis[i] = true;
	
			ct++;//每遇到一个可以加入组的数字，就试着形成一个组 
			int nextPos = getNextValidPos(n_i); 
			if(nextPos == n)//所有的数字都分配完毕 
			{
				if(ct < ctMin)//更新最小组数 
					ctMin = ct; 
				ct--;
				for(int i = 0;i < ind_n; ++i)//还原vis数组 
					vis[ind[i]] = false;
				return;
			}
			else
			{
				Search(nextPos);
				ct--;
			}
		}
	}
	for(int i = 0;i < ind_n; ++i)//还原vis数组 
		vis[ind[i]] = false;
}

int main()
{
	cin>>n;
	for(int i = 0;i < n; ++i)
		cin>>num[i];
	Search(0);
	cout<<ctMin;
	return 0;
}
