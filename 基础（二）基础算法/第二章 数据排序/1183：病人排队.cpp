#include<bits/stdc++.h>
using namespace std;

typedef struct Man
{
	char id[10];
	int age;
}Man;

int main()
{
	int n, io = 0, iy = 0;
	cin>>n;
	Man old[100], young[100], m;
	for(int i = 0; i < n; ++i)
	{
		cin>>m.id>>m.age;
		if(m.age >= 60)
		{
			int j;
			for(j = io-1; j >= 0; j--)//≤Â»Î≈≈–Ú 
			{
				if(old[j].age < m.age)
					old[j+1] = old[j];
				else
					break;
			}
			old[j+1] = m;
			io++;
		}
		else
			young[iy++] = m;
	}
	for(int i = 0; i < io; ++i)
		cout<<old[i].id<<endl;
	for(int i = 0; i < iy; ++i)
		cout<<young[i].id<<endl;
}
