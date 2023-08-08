#include <bits/stdc++.h>
using namespace std;
//本题用cout输出会超时，只能用printf
char s[3];//三个柱子都叫什么
//求除了编号为a,b的柱子，另一个柱子的编号是什么
int getOther(int a, int b)
{
    if(a == 0 && b == 1 || a == 1 && b == 0)
        return 2;
    else if(a == 0 && b == 2 || a == 2 && b == 0)
        return 1;
    else
        return 0;
}

//把柱子编号为s_f的前n层移动到柱子编号为s_t的柱子上，其中前n层一定是大小从1~n的盘子
//另一个柱子的编号是s_o
//需要把s_f的前n-1层移动到s_o上，再把s_f的1层移动到s_t上，再把s_o的n-1层移动到s_t上
void move(int s_f, int n, int s_t)
{
    if(n < 1)
        return;
    int s_o = getOther(s_f, s_t);
    move(s_f, n-1, s_o);
    //用cout输出会超时，只能用printf
    printf("%c->%d->%c\n", s[s_f], n, s[s_t]);//本次函数调用要移动前n层，那么此时会移动大小为n的盘子
    move(s_o, n-1, s_t);
}

int main()
{
    int n;
    cin>>n;
    cin>>s[0]>>s[1]>>s[2];
    move(0, n, 1);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
//非递归 用栈来解汉诺塔
//本题用cout输出会超时，只能用printf

//一次移动操作问题
typedef struct Move
{
    int s_f; //从哪
    int n; //移动到哪
    int s_t; //多少层
    bool isPrint; //是否输出，如果该问题是需要输出的，那么只输出，不做移动
    Move()
    {
        Move(0, 0, 0);
    }
    Move(int a, int b, int c)
    {
        s_f = a;
        n = b;
        s_t = c;
        isPrint = false;
    }
}Move;

//栈初始化
Move stk[1000];
int p;

char s[3];//三个柱子都叫什么
//求除了编号为a,b的柱子，另一个柱子的编号是什么
int getOther(int a, int b)
{
    if(a == 0 && b == 1 || a == 1 && b == 0)
        return 2;
    else if(a == 0 && b == 2 || a == 2 && b == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n, s_o;//s_o另一个柱子
    cin>>n;
    cin>>s[0]>>s[1]>>s[2];
    Move m0(0, n, 1), m, m1, m2;
    stk[++p] = m0;//初始问题压栈
    while(p != 0)//栈不为空
    {
        //取栈顶m问题
        m = stk[p];
        p--;//出栈
        if(m.isPrint == true || m.n == 1)//仅仅打印m操作 n为1时直接打印
        {
            printf("%c->%d->%c\n", s[m.s_f], m.n, s[m.s_t]);//本次函数调用要移动前n层，那么此时会移动大小为n的盘子
        }
        else
        {
            s_o = getOther(m.s_f, m.s_t);
            //m2问题：把前n-1层从s_o移动到s_t
            m2.n = m.n-1;
            m2.s_f = s_o;
            m2.s_t = m.s_t;
            stk[++p] = m2;//先压入m2
            //再压入只做打印操作的问题m
            m.isPrint = true;
            stk[++p] = m;
            //m1问题:把前n-1层从s_f移动到s_o
            m1.n = m.n-1;
            m1.s_f = m.s_f;
            m1.s_t = s_o;
            stk[++p] = m1;//最后压入m1
        }
    }
    return 0;
}
*/
