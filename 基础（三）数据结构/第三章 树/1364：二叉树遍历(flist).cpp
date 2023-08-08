#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    char val;
    int left, right;
}Node;
Node node[10000];
int p = 1, len;
char si[1000], sl[1000];//si:中序遍历字符串 sl:层次遍历字符串
//层次遍历时，处于前面位置的一定是在上面的结点。
//从前到后分别针对层次遍历字符串中的每一个元素，在中序遍历字符串si中搜索，若找到与其相等的元素，则该元素就是该中序遍历字符串对应的树的根。

//对si从si_l到si_r，为一个中序遍历字符串，将其转化为树，返回树的根的地址
int proc(int si_l, int si_r)
{
    if(si_l > si_r)
        return 0;
    int np = p++, si_t = si_l;
    for(int i = 0; i < len; ++i)//从低到高遍历层次遍历字符串，先取到的元素一定处于树的上层
    {
        bool hasRoot = false;
        for(int j = si_l; j <= si_r; ++j)//看中序遍历字符串si中哪个元素与sl[i]等同，如果存在，那么该元素就是这段中序遍历字符串对应的树的根
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
