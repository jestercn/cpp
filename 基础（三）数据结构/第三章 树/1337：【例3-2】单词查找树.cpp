#include <bits/stdc++.h>
using namespace std;
//二叉树结点
typedef struct
{
    char val;
    int left, right;
}Node;

Node node[40000];//结点池
int p;

//用孩子兄弟表示法，使用二叉树来表示树
int main()
{
    int np, selp, rootp = p++;//selp：选择的结点地址 rootp：根结点的地址 
    char word[65];
    while(cin>>word)
    {
        selp = rootp;
        for(int i = 0;i < strlen(word);++i)
        {
            if(node[selp].left == 0)//如果没有左孩子，把新结点添加到左孩子
            {
                np = p++;//设置新结点
                node[np].val = word[i];
                node[selp].left = np;
                selp = np;
            }
            else//从selp的左孩子开始，不断取右孩子，即遍历树的这一层
            {
                int j;
                for(j = node[selp].left; j!= 0; j = node[j].right)//j结点地址 遍历孩子，也就是树的这一层
                {
                    selp = j;//指向遍历到的最后一个结点。
                    if(word[i] == node[j].val)//这一层有与word[i]相同的字母，那么下一次遍历的父节点就是此时的j
                        break;
                }
                if(j == 0)//遍历到了树这一层的末尾，说明这层没有与word[i]相同的字母，应该在这一层添加新的字母结点
                {
                    np = p++;//设置新结点
                    node[np].val = word[i];
                    node[selp].right = np;
                    selp = np;
                }
            }
        }
    }
    cout<<p;//p的值，是已经分配出去的结点数量。由于该程序中没有结点删除，那么p的值就是树中的结点数。
}
