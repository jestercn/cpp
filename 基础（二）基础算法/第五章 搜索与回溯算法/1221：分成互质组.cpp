#include<bits/stdc++.h>
using namespace std;
//���裬����һ������Ҳ�������ڻ��ʵ�һ�� 
int n, num[15], ct, ctMin = INT_MAX;//ct:����� ctMin:��С����
bool vis[15];//vis[i] == true ��ʾ��i�������Ѿ����䵽һ������ 
bool isHuzhi(int a, int b)
{
	for(int i = 2; i <= a; ++i)
	{
		if(b % i == 0 && a % i == 0)//��a��b���ڴ���1�Ĺ�Լ��
			return false; 
	}
	return true;
}

//��num[n_i]�ܷ���뵱ǰ��g�� 
bool canEnterGroup(int g[], int g_n, int n_i)//g:һ���� g_n:����g�����ָ��� 
{
	for(int i = 0; i < g_n; ++i)
	{
		if(isHuzhi(g[i], num[n_i]) == false)
			return false;
	}
	return true;	
}

//��ȡn_i����ĵ�һ�� vis[i] == false��i
//���ҵ��ˣ������Ǹ�λ�õ��±꣬��δ�ҵ�������n 
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

//����ǰ��֤vis[n_i] == false
//��num[n_i]��ʼ�������,�γ�һ���� 
void Search(int n_i)
{
	int g[15], g_n = 0, ind[15], ind_n = 0;//g�������� g_n:g��Ԫ�ظ��� ind:g�б�����num����Щ�±������ 
	for(int i = n_i; i < n; ++i)
	{
		if(vis[i] == false && canEnterGroup(g, g_n, i))
		{
			g[g_n++] = num[i];
			ind[ind_n++] = i;
			vis[i] = true;
	
			ct++;//ÿ����һ�����Լ���������֣��������γ�һ���� 
			int nextPos = getNextValidPos(n_i); 
			if(nextPos == n)//���е����ֶ�������� 
			{
				if(ct < ctMin)//������С���� 
					ctMin = ct; 
				ct--;
				for(int i = 0;i < ind_n; ++i)//��ԭvis���� 
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
	for(int i = 0;i < ind_n; ++i)//��ԭvis���� 
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
