#include <bits/stdc++.h>
using namespace std;
//思路：由于结果是布尔值，某变量的改变只会导致两种结果：最终结果 变化 或 不变。
//构造表达式树，结点中存储：本结点值的改变能否使父节点的值改变。
//构造isChange数组，存储第i个变量变化后能否影响最终结果。构造方法为：isChange初始值都为0，从根结点向下遍历，若本结点值的变化不能影响父节点，那么不再向下遍历。
//否则不断遍历，直到遍历到叶子结点。那些遍历到的叶子结点对应的变量，就是其改变后可以影响最终结果的变量。
//最后，根据输入，在isChange数组中查询结果
typedef struct Node
{
    int left, right;//左右孩子地址
    bool val;//值
    bool inf;//本节点值的改变是否能影响父结点
    int x;//该结点的变量编号(指x后面的数字编号，如x1, x2, x3...)
}Node;
bool val[100005];//各x变量取值
char s[1000005];
Node node[1000005];//结点池
int ni = 1;//结点池下标
bool isChange[100005];//isChange[i] 第i个变量变化后，能否影响最终结果

//isChAnd[a][b][c]: 当第1个数的值是a，第2个数值是b时，第c+1个数的值变化能否影响运算的结果。
//例:0&0 = 0 第一个数0变为1，公式变为1&0 = 0，不能影响运算结果。那么有isChAnd[0][0][0] = false;
bool isChAnd[2][2][2], isChOr[2][2][2];
void initIsCh()//初始化两个isCh数组
{
    isChAnd[0][0][0] = 0;  isChAnd[0][0][1] = 0;
    isChAnd[0][1][0] = 1;  isChAnd[0][1][1] = 0;
    isChAnd[1][0][0] = 0;  isChAnd[1][0][1] = 1;
    isChAnd[1][1][0] = 1;  isChAnd[1][1][1] = 1;

    isChOr[0][0][0] = 1;  isChOr[0][0][1] = 1;
    isChOr[0][1][0] = 0;  isChOr[0][1][1] = 1;
    isChOr[1][0][0] = 1;  isChOr[1][0][1] = 0;
    isChOr[1][1][0] = 0;  isChOr[1][1][1] = 0;
}

//返回根节点的地址
int initTree()
{
    stack<int> stk;//栈，存放结点地址
    int xNum = 0, np, lp, rp;
    char cal;//保存运算符
    int len = strlen(s);
    for(int i = 0; i <= len; ++i)
    {
        if(s[i] >= '0' && s[i] <= '9')
            xNum = xNum * 10 + s[i] - '0';
        else if(s[i] == '&' || s[i] == '|' || s[i] == '!')
            cal = s[i];
        else if(s[i] == ' ' || s[i] == '\0')
        {
            if(xNum > 0)//提取出变量x
            {
                np = ni++;//从结点池申请结点
                node[np].val = val[xNum];//设置值
                node[np].x = xNum;//设置变量编号
                stk.push(np);
                xNum = 0;
            }
            else//提取出运算符
            {
                np = ni++;//从结点池申请结点
                if(cal == '!')
                {
                    lp = stk.top();
                    stk.pop();
                    node[lp].inf = true;
                    node[np].val = !node[lp].val;
                    node[np].left = lp;
                }
                else
                {
                    rp = stk.top();//左孩子地址
                    stk.pop();
                    lp = stk.top();//右孩子地址
                    stk.pop();
                    node[np].left = lp;
                    node[np].right = rp;
                    if(cal == '&')//生成新结点，设置结点值，及能否影响其父节点
                    {
                        node[np].val = node[lp].val && node[rp].val;
                        node[lp].inf = isChAnd[node[lp].val][node[rp].val][0];
                        node[rp].inf = isChAnd[node[lp].val][node[rp].val][1];
                    }
                    else if(cal == '|')
                    {
                        node[np].val = node[lp].val || node[rp].val;
                        node[lp].inf = isChOr[node[lp].val][node[rp].val][0];
                        node[rp].inf = isChOr[node[lp].val][node[rp].val][1];
                    }
                }
                stk.push(np);
            }
        }
    }
    return stk.top();//最后栈中剩下的是根节点
}

//遍历整棵树，初始化isChange数组
void initIsChange(int p)
{
    if(node[p].inf)//如果本结点能影响父节点
    {
        if(node[p].left == 0 && node[p].right == 0)
        {
            isChange[node[p].x] = true;
        }
        else
        {
            if(node[p].left != 0)
                initIsChange(node[p].left);
            if(node[p].right != 0)
                initIsChange(node[p].right);
        }
    }
}

int main()
{
    initIsCh();//初始化两个isCh数组
    int n, q, qi;
    bool res;//正常计算的结果
    gets(s);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &val[i]);
    int root = initTree();//生成树，获得根结点
    res = node[root].val;//根据各变量初始值得到的计算结果
    node[root].inf = true;//为了配合initIsChange函数，必须设这一点
    initIsChange(root);//生成isChange数组
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i)
    {
        scanf("%d", &qi);
        if(isChange[qi])//如果qi的变化能引起最终结果的变化
            printf("%d\n", !res);//最终结果变化了
        else
            printf("%d\n", res);//最终结果没变
    }
    return 0;
}
