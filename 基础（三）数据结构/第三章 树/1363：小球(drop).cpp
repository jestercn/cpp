#include <bits/stdc++.h>
using namespace std;

bool tree[1050000];//˳��洢�ṹ������ ��ʼֵΪfalse
int main()
{
    int par_d, par_i, p = 1;//par_d,par_iΪ����Ĳ���D��I, pΪ��ʱָ��Ľ���������е��±� ��1λ�������ĸ�
    cin>>par_d>>par_i;
    for(int i = 0; i < par_i; ++i)
    {
        p = 1;
        for(int d = 1; d < par_d; ++d)//Ҷ�ӽ����һ�㲻�ü���
        {
            if(tree[p])
            {
                tree[p] = false;
                p = 2 * p + 1;//��������
            }
            else
            {
                tree[p] = true;
                p = 2 * p;//��������
            }
        }
    }
    cout<<p;
    return 0;
}
