#include <bits/stdc++.h>
using namespace std;
//�߾��ȳ��Ը߾��� 
//�Ƚ������������� ���a��b�󣬷���1�����a��bС������-1�����������ȣ�����0
int numcmp(int a[], int b[])
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

//����������b���Ƶ���������a֮��
void numcpy(int a[], int b[])
{
    for(int i = 0; i <= b[0]; ++i)
        a[i] = b[i];
}

//�߾��ȼ�������
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

//�߾��ȳ����еļ����������������ʵ�ʾ��ǳ�������һ��ʵ�ַ�ʽ
//a�Ǳ����� b�ǳ���
//����ֵΪ�̣����������a�����������
int minusInDivide(int a[], int b[])
{
    int minusTimes = 0;//minusTimes�����Ĵ���
    int r[1000] = {};
    while(true)
    {
        if(numcmp(a, b) < 0)
        {
            return minusTimes;
        }
        else
        {
            Minus(a, b, r);
            numcpy(a, r);//��a��Ϊ�ϴμ����Ľ��
            minusTimes++;
        }
    }
}

//����������ĸ�λ���һλ����0 <= num <= 9
void addNum(int a[], int num)
{
    for(int i = a[0]; i >= 1; --i)//������λ
    {
        a[i+1] = a[i];
    }
    a[1] = num;
    a[0]++;
}

//�߾������ֳ��Ը߾�������
void Divide(int a[], int b[], int r[])
{
    int x[1000] = {};//x:�м���ʱʹ�õ����֣�����һ�β��ϼ��������µ������Լ���Ϊ��һ�εı�����
    for(int i = a[0]; i >= 1; --i)
    {
        addNum(x, a[i]);
        r[i] = minusInDivide(x, b);
    }
    int r_i = a[0];//ɾ�������0
    while(r[r_i] == 0 && r_i > 1)
        r_i--;
    r[0] = r_i;
}

//�߾������ֶԸ߾�������ȡģ
void Mod(int a[], int b[], int x[])
{
    for(int i = a[0]; i >= 1; --i)
    {
        addNum(x, a[i]);
        minusInDivide(x, b);
    }
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
    int a[1000] = {}, b[1000] = {}, r[1000] = {}, x[1000] = {};
    char s[1000];
    cin>>s;
    toNumArr(s, a);
    cin>>s;
    toNumArr(s, b);
    Divide(a, b, r);
    Mod(a, b, x);
    showNum(r);
    showNum(x);
}
