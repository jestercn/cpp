#include <bits/stdc++.h>
using namespace std;
//���������
typedef struct
{
    char val;
    int left, right;
}Node;

Node node[40000];//����
int p;

//�ú����ֵܱ�ʾ����ʹ�ö���������ʾ��
int main()
{
    int np, selp, rootp = p++;//selp��ѡ��Ľ���ַ rootp�������ĵ�ַ 
    char word[65];
    while(cin>>word)
    {
        selp = rootp;
        for(int i = 0;i < strlen(word);++i)
        {
            if(node[selp].left == 0)//���û�����ӣ����½����ӵ�����
            {
                np = p++;//�����½��
                node[np].val = word[i];
                node[selp].left = np;
                selp = np;
            }
            else//��selp�����ӿ�ʼ������ȡ�Һ��ӣ�������������һ��
            {
                int j;
                for(j = node[selp].left; j!= 0; j = node[j].right)//j����ַ �������ӣ�Ҳ����������һ��
                {
                    selp = j;//ָ������������һ����㡣
                    if(word[i] == node[j].val)//��һ������word[i]��ͬ����ĸ����ô��һ�α����ĸ��ڵ���Ǵ�ʱ��j
                        break;
                }
                if(j == 0)//������������һ���ĩβ��˵�����û����word[i]��ͬ����ĸ��Ӧ������һ������µ���ĸ���
                {
                    np = p++;//�����½��
                    node[np].val = word[i];
                    node[selp].right = np;
                    selp = np;
                }
            }
        }
    }
    cout<<p;//p��ֵ�����Ѿ������ȥ�Ľ�����������ڸó�����û�н��ɾ������ôp��ֵ�������еĽ������
}
