#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int bigger;
    if(a > b)
        bigger = a;
    else
        bigger = b;

    if(bigger > c)
        cout<<bigger;
    else
        cout<<c;
}
/*
//�ⷨ2 ���߼����ʽ 
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    if (a > b && a > c)
        cout<<a;
    else if (a > b && a <= c)
        cout<<c;
    else if (a <= b && b > c)
        cout<<b;
    else
        cout<<c;
}
//�ⷨ3���ú��� 
int bigger(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int a, b, c;
    cin>>a>>b>>c;
	cout<<bigger(a, bigger(b, c));
}
*/
