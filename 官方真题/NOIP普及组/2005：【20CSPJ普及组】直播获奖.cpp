//Ͱ����
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int buk[700];
int getNum(int p, int w)
{
	int pos = max(1, p * w / 100);//Ҫ�ҵ�posλ�ĳɼ�
	for(int i = 600; i >= 0; --i)//�Ӹ߷ֿ����ͷ�
	{
		pos -= buk[i];//λ����ȥ�������������
		if(pos <= 0)//���λ������0�ˣ�˵����һ�������Ƿ�����
			return i;
	}
}

int main()
{
	int n, w, g, i, line;//line:������
	scanf("%d %d", &n, &w);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &g);
		buk[g]++;
		printf("%d ", getNum(i, w));
	}
	return 0;
}
