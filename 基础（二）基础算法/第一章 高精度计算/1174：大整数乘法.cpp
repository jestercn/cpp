#include <bits/stdc++.h>
using namespace std;
//�߾��ȳ˷�
void Multiply(int a[], int b[], int r[])
{
    for(int i = 1; i <= a[0]; ++i)
    {
        int c = 0;
        for(int j = 1; j <= b[0]; ++j)
        {
            r[i+j-1] = a[i]*b[j] + c + r[i+j-1];
            c = r[i+j-1] / 10;
            r[i+j-1] %= 10;
        }
        r[i+b[0]] += c;
    }
    int r_i = a[0] + b[0];//ȥ�������0
    while(r[r_i] == 0 && r_i > 1)
        r_i--;
    r[0] = r_i;
}

//���ַ�����ת��Ϊ�������� ��������ӵ�1λ�õ���lenλ�ã��ӵ�λ����λ�����λ���֣���0λ�ñ�������λ��
void toNumArr(char s[], int a[])
{
    int len = strlen(s);
    a[0] = len;
    for(int i = 0; i < len; ++i)
    {
        a[i + 1] = s[len - 1 - i] - '0';
    }
}

void showNum(int a[])
{
    for(int i = a[0]; i >= 1; --i)
        cout<<a[i];
    cout<<endl;
}

int main()
{
    int a[1000]={}, b[1000]={}, r[1000]={};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    cin>>s;
    toNumArr(s, b);
    Multiply(a, b, r);
    showNum(r);
}
