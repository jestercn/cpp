#include <iostream>
using namespace std;
//思路：全排列
//针对长度为n的数组的全排列，是把每个元素逐次放在第0位置，其余元素顺序排序，而后对第1~第n-1元素进行全排列
//当要排列的元素只有1个时，输出此时的数组

char s[8];
//字符数组b的第l到第r元素拷贝到数组a的对应位置 
void cpy(char a[], char b[], int l, int r)
{
	for(int i = l; i <= r; ++i)
		a[i] = b[i];
}
//对数组s第l~第r元素进行全排列
void arrange(int l, int r)
{
	if(l == r)//如果要排列的元素只有1个，那么此次排列结束，应该输出整个数组 
	{
		for(int i = 0; i < strlen(s); ++i)
			cout<<s[i];
		cout<<endl;
	}
	else
	{
		char oris[8];
		cpy(oris, s, l, r);//记录此时s，以下循环以oris为基准 
		for(int i = l; i <= r; ++i)
		{
			cpy(s, oris, l, r);
			char temp = s[i];//把第j元素提到第i位置，第j-1~第l元素右移 
			for(int j = i - 1; j >= l; --j)
				s[j + 1] = s[j];
			s[l] = temp;//把原来第i位置的元素放在第l位置 
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
