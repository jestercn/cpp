#include <bits/stdc++.h>
using namespace std;
/*要填入Blah数集的一共有两类数
第一类：由2x+1生成的
第二类：由3x+1生成的
那么开两个队列que2,que3，分别存储由2x+1和3x+1生成的数字。
然后这两个队列队首比较，哪个小，哪个出队。
用一个变量lastNum保存上一次出队的数字，若此时出队的数字等于lastNum，那么计数不增加（因为集合中相同数字算1个），否则计数增加。
计数增加后，将刚刚出队的数字设为lastNum，并将2*lastNum+1, 3*lastNum+1分别入队
直到计数增长到n，此时lastNum就为数集中第n小的元素
*/
//声明两个队列
int que2[1000005], que3[1000005];
int h_2, t_2, h_3, t_3;//两个队列的头尾指针

//获取Blah数集的第n个数，initNum为初始数字
int getBlahN(int initNum, int n)
{
    h_2=t_2=h_3=t_3=0;//清空两个队列
    int count = 0, lastNum = initNum, tempNum;//count计数，lastNum上一次出队的数字，tempNum临时数字
    count++;
    que2[++t_2] = 2*lastNum + 1;//入队
    que3[++t_3] = 3*lastNum + 1;
    while(count<n)
    {
        if(que2[h_2+1] < que3[h_3+1])//队首比较
        {
            tempNum = que2[++h_2];//队列2出队
        }
        else if(que2[h_2+1] > que3[h_3+1])
        {
            tempNum = que3[++h_3];//队列3出队
        }
        else//二者相等，都出队
        {
            tempNum = que2[++h_2];
            ++h_3;
        }
        if(lastNum != tempNum)//如果取出的数字与上一个数字不等
        {
            count++;
            lastNum = tempNum;
            que2[++t_2] = 2*lastNum + 1;//入队
            que3[++t_3] = 3*lastNum + 1;
        }
    }
    return lastNum;
}

int main()
{
    int a, n;
    while(cin>>a>>n)
    {
        cout<<getBlahN(a, n)<<endl;
    }
	return 0;
}
