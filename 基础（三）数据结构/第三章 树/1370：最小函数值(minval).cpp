#include <bits/stdc++.h>
using namespace std;
//由于a>0，二次函数开口向上，顶点位置横坐标为-b/(2a)，已知本题中a,b,x都为正整数，那么顶点横坐标在负半轴
//在x>0的范围内，二次函数是增函数。对于该函数来说，x=1时函数值最小，x=2时函数值第二小。。。
//使用堆排序
//把二元一次方程设为结点，以方程的值大小进行堆排序，构筑小顶堆。每次取堆顶，获得各方程中的最小值，让该方程离开堆，然后该方程的x加1，再加入这个堆。
typedef struct Equation//表示一个二元一次方程
{
    int a, b, c, x;
    Equation(int _a, int _b, int _c, int _x):a(_a), b(_b), c(_c), x(_x)
    {
    }
    Equation()
    {
    }
    int getVal()
    {
        return a*x*x + b*x + c;
    }
    bool operator<(Equation& e)//重载运算符 
    {
        return this->getVal() < e.getVal();
    }
    bool operator>(Equation& e)
    {
        return this->getVal() > e.getVal();
    }
}Equation;

//小顶堆
//由于小顶堆是完全二叉树，使用顺序存储结构表示二叉树
typedef struct Heap
{
    Equation tree[10005];//从第1位置开始保存
    int len;//堆中元素个数
    Heap()
    {
        len = 0;
    }
    void addVal(Equation e)//添加一个值，并调整
    {
        tree[++len] = e;
        adjUp(len);
    }
    void adjUp(int pos)//从第pos位置开始，从下至上调整
    {
        if(pos > 1)
        {
            if(tree[pos] < tree[pos/2])//如果孩子比父亲小
            {
                swap(tree[pos], tree[pos/2]);
                adjUp(pos/2);
            }
        }
    }
    void adjDown(int pos)//从第pos位置开始，从上至下调整
    {
        int nextPos;
        if(pos * 2 > len && pos*2 + 1 > len)//pos为叶子结点
            return;
        else if(pos*2 + 1 > len)//有左孩子没有右孩子
            nextPos = pos * 2;
        else
        {
            if(tree[pos*2] > tree[pos*2 + 1])
                nextPos = pos*2 + 1;
            else
                nextPos = pos*2;
        }
        if(tree[pos] > tree[nextPos])
        {
            swap(tree[pos], tree[nextPos]);
            adjDown(nextPos);
        }
    }
    Equation getAndRemoveTop()//获取顶部结点的值并去掉顶部结点
    {
        Equation top = tree[1];
        swap(tree[len], tree[1]);//顶部结点和末尾结点调换
        len--;
        adjDown(1);
        return top;
    }
}Heap;
int main()
{
    Heap heap;
    Equation e;
    int n, m, a, b, c;
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
    {
        cin>>a>>b>>c;
        heap.addVal(Equation(a, b, c, 1));
    }
    for(int i = 0;i < m; ++i)
    {
        e = heap.getAndRemoveTop();
        cout<<e.getVal()<<' ';
        e.x++;
        heap.addVal(e);
    }
    return 0;
}
