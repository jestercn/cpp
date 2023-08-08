#include <bits/stdc++.h>
using namespace std;

typedef struct//二叉树结点
{
    char val;
    int left, right;
}Node;

Node node[10000];//结点池
int p = 1;

void inOrder(int p_r)
{
    if(p_r != 0)
    {
        inOrder(node[p_r].left);
        cout<<node[p_r].val;
        inOrder(node[p_r].right);
    }
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
//传入要生成的二叉树的根的值，返回生成的二叉树的地址
int createTree(char val)
{
    int np;
    if(val == '.')
        return 0;
    else
    {
        np = p++;
        node[np].val = val;
        node[np].left = createTree(getchar());
        node[np].right = createTree(getchar());
        return np;
    }
}
int main()
{
    int p_root = createTree(getchar());
    inOrder(p_root);
    cout<<endl;
    postOrder(p_root);
    return 0;
}
