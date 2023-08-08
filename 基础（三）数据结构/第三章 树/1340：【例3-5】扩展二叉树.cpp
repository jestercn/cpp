#include <bits/stdc++.h>
using namespace std;

typedef struct//���������
{
    char val;
    int left, right;
}Node;

Node node[10000];//����
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
//����Ҫ���ɵĶ������ĸ���ֵ���������ɵĶ������ĵ�ַ
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
