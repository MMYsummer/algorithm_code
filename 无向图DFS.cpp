#include <bits/stdc++.h>
using namespace std;

int maze[500][500];	//某景观到另一景观的游步道长度
int vis[100];	//记录已到达的景观点 
int n,m;	//景观数，游步道总数  
int maxs = 0;

void dfs(int lot,int sums)	//当前的点,当前路程   
{
	maxs = max(maxs,sums);
	for(int i=1;i<=n;i++)	//搜索下个景观  
	{
		if(vis[i]==0 && maze[lot][i]!=0)	//未去过 且当点与下一个点有路	
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
		maze[a][b] = l;		//a到b和b到a的路程都要记录 无向图 
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
