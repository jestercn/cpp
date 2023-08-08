#include <bits/stdc++.h>
using namespace std;

typedef struct//���������
{
    char val;
    int left, right;
}Node;

Node node[10000];//����
int p = 1;

char sp[1000], si[1000];//����������ַ���

//sp_l, sp_r Ϊsp������±꣬si_l��si_rΪsi������±�
//�ú���Ϊ��sp,si�������У�sp��sp_l��sp_r��si��si_l��si_r���������飬һ�������������һ�������������������������ظ������ĵ�ַ
int proc(int sp_l, int sp_r, int si_l, int si_r)
{
    if(sp_l > sp_r || si_l > si_r)
        return 0;
    int np = p++;
    node[np].val = sp[sp_l];//��������ַ����е�һ��Ԫ��Ϊ������ֵ
    int si_t = si_l;//�����ֵ����������е�λ��
    int lcount = 0;//��������У������ֵ����Ԫ������
    for(int i = si_l; i <= si_r; ++i)//����������У���һ���������ֵ��ͬ
    {
        if(si[i] == sp[sp_l])
        {
            si_t = i;
            break;
        }
        lcount++;
    }
    node[np].left = proc(sp_l + 1, sp_l + lcount, si_l, si_t - 1);//ָ�������������������������� �����������
    node[np].right = proc(sp_l + lcount + 1, sp_r, si_t + 1, si_r);//ָ�������������������������� �����������
    return np;
}

void postOrder(int p_r)
{
    if(p_r != 0)
    {
        postOrder(node[p_r].left);
        postOrder(node[p_r].right);
        cout<<node[p_r].val;
    }
}
//��֪���������������������
int main()
{
    cin>>sp>>si;
    int len = strlen(sp);
    int p_root = proc(0, len - 1, 0, len - 1);
    postOrder(p_root);
}
