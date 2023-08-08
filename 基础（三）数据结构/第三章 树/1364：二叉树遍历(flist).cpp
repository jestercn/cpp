#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    char val;
    int left, right;
}Node;
Node node[10000];
int p = 1, len;
char si[1000], sl[1000];//si:��������ַ��� sl:��α����ַ���
//��α���ʱ������ǰ��λ�õ�һ����������Ľ�㡣
//��ǰ����ֱ���Բ�α����ַ����е�ÿһ��Ԫ�أ�����������ַ���si�����������ҵ�������ȵ�Ԫ�أ����Ԫ�ؾ��Ǹ���������ַ�����Ӧ�����ĸ���

//��si��si_l��si_r��Ϊһ����������ַ���������ת��Ϊ�����������ĸ��ĵ�ַ
int proc(int si_l, int si_r)
{
    if(si_l > si_r)
        return 0;
    int np = p++, si_t = si_l;
    for(int i = 0; i < len; ++i)//�ӵ͵��߱�����α����ַ�������ȡ����Ԫ��һ�����������ϲ�
    {
        bool hasRoot = false;
        for(int j = si_l; j <= si_r; ++j)//����������ַ���si���ĸ�Ԫ����sl[i]��ͬ��������ڣ���ô��Ԫ�ؾ��������������ַ�����Ӧ�����ĸ�
        {
            if(sl[i] == si[j])
            {
                hasRoot = true;
                si_t = j;
                break;
            }
        }
        if(hasRoot)
            break;
    }
    node[np].val = si[si_t];
    node[np].left = proc(si_l, si_t - 1);;
    node[np].right = proc(si_t + 1, si_r);
    return np;
}

void preOrder(int p_r)
{
    if(p_r != 0)
    {
        cout<<node[p_r].val;
        preOrder(node[p_r].left);
        preOrder(node[p_r].right);
    }
}
int main()
{
    cin>>si>>sl;
    len = strlen(si);
    int p_root = proc(0, len - 1);
    preOrder(p_root);
    return 0;
}
