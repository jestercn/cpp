#include<bits/stdc++.h>
using namespace std;

int main()
{
	bool isFound = false;
    int a[6][6];
    for(int i = 1; i <= 5; ++i)
    	for(int j = 1; j <= 5; ++j)
    		cin>>a[i][j];
	for(int i = 1; i <= 5; ++i)//�ҵ�ÿ�е����ֵ�������жϸ�ֵ�Ƿ�����һ�е���Сֵ 
	{
		int max = a[i][1], m_j = 1;//m_j���ֵ��j���� 
		for(int j = 2; j <= 5; ++j)//������i�У�j���кţ��ҵ����ֵ 
		{
			if(a[i][j] > max)
			{
				max = a[i][j];
				m_j = j;
			}
		}
		bool isAndian = true;//a[i][m_j]�Ƿ��ǰ��� 
		for(int k = 1; k <= 5; ++k)//������m_j�� k���к� 
		{
			if(a[k][m_j] < a[i][m_j])//ֻҪ�ڵ�m_j���ҵ�һ��С��a[i][m_j]��Ԫ�أ���ô�õ�Ͳ��ǰ��� 
			{
				isAndian = false;
				break;
			}
		}
		if(isAndian)//������ڰ��� 
		{
			cout<<i<<' '<<m_j<<' '<<a[i][m_j]<<endl;
			isFound = true;
		}	
	}
	if(isFound == false)
		cout<<"not found"<<endl;
    return 0;
}
