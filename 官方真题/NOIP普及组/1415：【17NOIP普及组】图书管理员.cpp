#include <bits/stdc++.h>
using namespace std;
#define N 1005
//思路：给图书编码排序
//考察：排序，枚举
//对于每个读者需求码，按图书编码从小到大遍历，找到一个相匹配的图书编码，即输出。
int mi[10];//存储10的幂
//图书编码bk与需求码rd是否匹配，即rd是否是bk的末尾几位数字。l是rd的位数
//算法示例：bk为2123，rd为123，看bk % 10^3的结果是不是rd，如果是，那么bk的末尾是rd，否则不是。
bool isMatch(int bk, int rd, int l)
{
    return bk % mi[l] == rd;
}
//初始化mi数组，存储10的幂
void initMi()
{
    int num = 10;
    for(int i = 1; i <= 9; ++i)
    {
        mi[i] = num;
        num *= 10;
    }
}

int main()
{
    initMi();
    int n, q, num;
    int len, reader;//len:读者需求码的长度, reader:读者的需求码
    int book[N];//book[i]:第i本书的编码
    cin>>n>>q;
    for(int i = 1; i <= n; ++i)//输入的同时做插入排序，形成从小到大的序列
    {
        scanf("%d", &num);
        int j;
        for(j = i; j > 1; --j)
        {
            if(num < book[j - 1])
                book[j] = book[j - 1];
            else
                break;
        }
        book[j] = num;
    }
    for(int i = 1; i <= q; ++i)//遍历读者需求码
    {
        cin>>len>>reader;//读入需求码长度，和需求码
        bool isShow = false;
        for(int j = 1; j <= n; ++j)//遍历排好序的图书编码数组
        {
            if(isMatch(book[j], reader, len))//如果图书编码和需求码匹配
            {
                cout<<book[j]<<endl;//输出图书编码
                isShow = true;
                break;
            }
        }
        if(isShow == false)//如果没有图书编码，输出-1
            cout<<-1<<endl;
    }
    return 0;
}
