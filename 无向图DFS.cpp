#include <bits/stdc++.h>
using namespace std;

int maze[500][500];	//ĳ���۵���һ���۵��β�������
int vis[100];	//��¼�ѵ���ľ��۵� 
int n,m;	//���������β�������  
int maxs = 0;

void dfs(int lot,int sums)	//��ǰ�ĵ�,��ǰ·��   
{
	maxs = max(maxs,sums);
	for(int i=1;i<=n;i++)	//�����¸�����  
	{
		if(vis[i]==0 && maze[lot][i]!=0)	//δȥ�� �ҵ�������һ������·	
		{
			vis[i] = 1;
			dfs(i,sums+maze[lot][i]);
			vis[i] = 0;	
		} 
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b,l;
		cin>>a>>b>>l;
		maze[a][b] = l;		//a��b��b��a��·�̶�Ҫ��¼ ����ͼ 
		maze[b][a] = l;
	}
	for(int i=1;i<=n;i++)
	{
		vis[i] = 1;
		dfs(i,0);
		vis[i] = 0;
	}
	cout<<maxs<<endl;	
	return 0;
}
/*https://www.luogu.org/problem/P1294*/
/*
9 6
1 7 68
9 8 80
2 6 18
7 6 40
4 7 68
9 1 65

281

*/
