#include <bits/stdc++.h>
using namespace std;
//����ɢ�д洢˼�� 
int main()
{
    int a[26] = {};//����a��0~��25Ԫ�طֱ𱣴�'a'���ֵĴ�����'b'���ֵĴ���...'z'���ֵĴ���
	char s[100005];
	scanf("%s", s);
	int len = strlen(s);//strlen��O(n)�ĸ��Ӷȣ����ַ����ܳ�ʱ�����ٵ���strlen�Ĵ��������ڼ�������ʱ�� 
	for(int i = 0; i < len; ++i)
	{
		a[s[i] - 'a']++;
	}
	for(int i = 0; i < len; ++i)//�����ַ������ҵ���һ��ֻ����һ�ε��ַ� 
	{
		if(a[s[i]-'a'] == 1)
		{
			printf("%c", s[i]);
			return 0;
		}
	}
	printf("no");//û�ҵ� 
    return 0;
}
