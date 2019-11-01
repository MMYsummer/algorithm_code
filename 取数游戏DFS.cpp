#include <bits/stdc++.h>
using namespace std;

int maze[100][100];	//图 
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};	//方向 
int n,m;//行列 
int vis[100][100];	//标记是否能选 
int maxs = 0;
void  visf(int r,int c,int o)	//将取的数八个方向设为不能选或复位  
{
	vis[r][c] += o;
	for(int i=0;i<8;i++)
	{
		if(r>0 && r<=n && c>0 && c<=m)	//未越界 
		{
			vis[r+dir[i][0]][c+dir[i][1]] += o;	//标记 用+=为了复位时不会将之前已选的错误的重置 
		}
	}
}

void dfs(int r,int c,int ans)
{
	maxs = max(maxs,ans);
	int dc = c+1,dr = r;
	if(dc>m)	//换行 
	{
		dr++;
		dc = 1;
		if(dr>n) return;	//越界 
	}
	if(vis[dr][dc]==0)	//未取
	{
		visf(dr,dc,1);	 
		dfs(dr,dc,ans+maze[dr][dc]);
		visf(dr,dc,-1);	
	}
	dfs(dr,dc,ans);	//不选 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		maxs = 0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&maze[i][j]);
		visf(1,1,1);
		dfs(1,1,maze[1][1]);
		memset(vis,0,sizeof(vis));
		dfs(1,1,0);
		memset(vis,0,sizeof(vis));		
		cout<<maxs<<endl;
	}
	return 0;
}
/*https://www.luogu.org/problem/P1123*/
/*
3
4 4
67 75 63 10
29 29 92 14
21 68 71 56
8 67 91 25
2 3
87 70 85
10 3 17
3 3
1 1 1
1 99 1
1 1 1

271
172
99

*/
