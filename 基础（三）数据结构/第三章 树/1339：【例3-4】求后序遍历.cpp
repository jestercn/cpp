#include <bits/stdc++.h>
using namespace std;

typedef struct//二叉树结点
{
    char val;
    int left, right;
}Node;

Node node[10000];//结点池
int p = 1;

char sp[1000], si[1000];//先序和中序字符串

//sp_l, sp_r 为sp数组的下标，si_l，si_r为si数组的下标
//该函数为，sp,si两数组中，sp从sp_l到sp_r，si从si_l到si_r，两段数组，一个是先序遍历，一个是中序遍历，求该子树，返回该树根的地址
int proc(int sp_l, int sp_r, int si_l, int si_r)
{
    if(sp_l > sp_r || si_l > si_r)
        return 0;
    int np = p++;
    node[np].val = sp[sp_l];//先序遍历字符串中第一个元素为根结点的值
    int si_t = si_l;//根结点值在中序遍历中的位置
    int lcount = 0;//中序遍历中，根结点值左侧的元素数量
    for(int i = si_l; i <= si_r; ++i)//看中序遍历中，哪一个与根结点的值相同
    {
        if(si[i] == sp[sp_l])
        {
            si_t = i;
            break;
        }
        lcount++;
    }
    node[np].left = proc(sp_l + 1, sp_l + lcount, si_l, si_t - 1);//指明左子树的先序和中序遍历序列 求子树根结点
    node[np].right = proc(sp_l + lcount + 1, sp_r, si_t + 1, si_r);//指明右子树的先序和中序遍历序列 求子树根结点
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
//已知先序中序遍历，求后序遍历
int main()
{
    cin>>sp>>si;
    int len = strlen(sp);
    int p_root = proc(0, len - 1, 0, len - 1);
    postOrder(p_root);
}
