#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, sel_i, sel_j, a[15][15];//sel_i sel_jѡ��λ�õĺ������� 
	scanf("%d %d %d", &n, &sel_i, &sel_j);
	for(int j = 1; j <= n; ++j)
		printf("(%d,%d) ", sel_i, j);
	putchar('\n');
	for(int i = 1; i <= n; ++i)
		printf("(%d,%d) ", i, sel_j);
	putchar('\n');
	
	int f_i = sel_i, f_j = sel_j;//Ѱ����(i,j)��ͬһ�������¶Խ����ϣ����Ϸ��ĵ�һ��λ�� 
	while(f_i > 1 && f_j > 1)
	{//�����Ϸ��ĸ��� 
		f_i--;
		f_j--;
	}
	//��ʱf_i,f_j���ǶԽ��������Ͻǵ�һ��λ��
	for(int i = f_i, j = f_j; i <= n && j <= n; ++i, ++j)
	{
		printf("(%d,%d) ", i, j);
	}
	putchar('\n');
	
	f_i = sel_i, f_j = sel_j;//Ѱ����(i,j)��ͬһ�������¶Խ����ϣ����·��ĵ�һ��λ�� 
	while(f_i < n && f_j > 1) 
	{//�����·��ĸ��� 
		f_i++;
		f_j--;
	}
	//��ʱf_i,f_j���ǶԽ��������½ǵ�һ��λ��
	for(int i = f_i, j = f_j; i >= 1 && j <= n; --i, ++j)
	{
		printf("(%d,%d) ", i, j);
	}
	return 0;
}
