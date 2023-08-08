#include <bits/stdc++.h>
using namespace std;
typedef struct Frac
{
    int num;//numerator ����
    int den;//denominator ��ĸ
    void trim()//������Լ
    {
        int small = num > den ? den : num;
        int i = 2;
        while(i <= small)
        {
            if(num % i == 0 && den % i == 0)
            {
                num /= i;
                den /= i;
            }
            else
                i++;
        }
    }
    void show()//�����������ʽ���
    {
        trim();
        if(den == 1)
            cout<<num;
        else
            cout<<num<<'/'<<den;
    }
}Frac;

Frac add(Frac fr1, Frac fr2)
{
    Frac fr_res;
    fr_res.den = fr1.den * fr2.den;
    fr_res.num = fr1.num * fr2.den + fr2.num * fr1.den;
    fr_res.trim();
    return fr_res;
}

//Frac strToFrac(char s[])//��֪���ӷ�ĸ��С�ڵ���10
//{
//    Frac res;
//    res.num = s[0] - '0';
//    res.den = s[2] - '0';
//    return res;
//}

int main()
{
    char s[10];
    Frac res, fr;
    int n;
    cin>>n;
    scanf("%d/%d", &res.num, &res.den);;//�Ȱѵ�һ������������
    for(int i = 1; i < n; ++i)
    {
        scanf("%d/%d", &fr.num, &fr.den);
        res = add(res, fr);
    }
    res.show();
    return 0;
}
