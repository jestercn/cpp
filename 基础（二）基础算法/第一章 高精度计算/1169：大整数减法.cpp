#include <bits/stdc++.h>
using namespace std;
//�߾��ȼ���

//�߾��ȼ�����������������a>=b��a��b�����������飬r������
void Minus(int a[], int b[], int r[])
{
    int i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        if(a[i] < b[i])
        {
            a[i+1]--;
            a[i] += 10;
        }
        r[i] = a[i] - b[i];
    }
    while(r[i] == 0 && i > 1)//ȥ�������0
        i--;
    r[0] = i;
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
//�Ƚ������������� ���a��b�󣬷���1�����a��bС������-1�����������ȣ�����0
int compare(int a[], int b[])
{
    if(a[0] > b[0])//���a��λ���Ƚ϶�
        return 1;
    else if (a[0] < b[0])//���b��λ���Ƚ϶�
        return -1;
    else
    {
        for(int i = a[0]; i >= 1; --i)
        {
            if(a[i] > b[i])
                return 1;
            else if(a[i] < b[i])
                return -1;
        }
        return 0;
    }
}

int main()
{
    int a[1000]={}, b[1000]={}, r[1000]={};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    cin>>s;
    toNumArr(s, b);
    if(compare(a, b) < 0)
    {
        cout<<'-';
        Minus(b, a, r);
    }
    else
        Minus(a, b, r);
    showNum(r);
}
