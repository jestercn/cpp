#include <iostream>
using namespace std;
//˼·��ȫ����
//��Գ���Ϊn�������ȫ���У��ǰ�ÿ��Ԫ����η��ڵ�0λ�ã�����Ԫ��˳�����򣬶���Ե�1~��n-1Ԫ�ؽ���ȫ����
//��Ҫ���е�Ԫ��ֻ��1��ʱ�������ʱ������

char s[8];
//�ַ�����b�ĵ�l����rԪ�ؿ���������a�Ķ�Ӧλ�� 
void cpy(char a[], char b[], int l, int r)
{
	for(int i = l; i <= r; ++i)
		a[i] = b[i];
}
//������s��l~��rԪ�ؽ���ȫ����
void arrange(int l, int r)
{
	if(l == r)//���Ҫ���е�Ԫ��ֻ��1������ô�˴����н�����Ӧ������������� 
	{
		for(int i = 0; i < strlen(s); ++i)
			cout<<s[i];
		cout<<endl;
	}
	else
	{
		char oris[8];
		cpy(oris, s, l, r);//��¼��ʱs������ѭ����orisΪ��׼ 
		for(int i = l; i <= r; ++i)
		{
			cpy(s, oris, l, r);
			char temp = s[i];//�ѵ�jԪ���ᵽ��iλ�ã���j-1~��lԪ������ 
			for(int j = i - 1; j >= l; --j)
				s[j + 1] = s[j];
			s[l] = temp;//��ԭ����iλ�õ�Ԫ�ط��ڵ�lλ�� 
			arrange(l + 1, r); 
		}
	}
}

int main()
{
	cin>>s;
	arrange(0, strlen(s)-1);
	return 0;
}
