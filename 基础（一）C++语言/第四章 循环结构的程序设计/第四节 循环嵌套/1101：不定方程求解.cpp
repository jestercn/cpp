#include <bits/stdc++.h>
using namespace std;
//�Բ�������ax+by = c
//a,b,c������������x,y�����ǷǸ�������
//��ô����ʹ�ñ�������x��y�ֱ��0ѭ����c������ax+by�Ľ���Ƿ����c
int main()
{
    int a, b, c, count = 0;
    cin>>a>>b>>c;
    for(int x = 0; x <= c; ++x)
        for(int y = 0; y <= c; ++y)
        {
            if(a*x + b*y == c)
                count++;
        }
    cout<<count;
    return 0;
}

