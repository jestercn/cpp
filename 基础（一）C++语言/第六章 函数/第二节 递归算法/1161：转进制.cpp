#include<bits/stdc++.h>
using namespace std;
//��nת��Ϊb���� 
//����ÿ��n%bȡ�����λ����ô�ȵ���toBase()����������λ�� 
void toBase(int n, int b)
{
	if(n == 0)
		return;
	toBase(n / b, b);
	if(n % b >= 10)
		cout<<char('A' + n % b - 10);
	else
		cout<<n % b;
}

int main()
{
	int n, b;
	cin>>n>>b;
	toBase(n, b);
	return 0;
}
