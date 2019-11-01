#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
char maze[maxn][maxn];
int idx[maxn][maxn],n,m;	//连通量编号数组 
int dirx[] = {-1,0,1};
int diry[] = {-1,0,1};

void dfs(int x,int y,int id)
{
	if(x<0 || y<0 || x>=m || y>=n) return;	// 越界
	if(idx[y][x] > 0 || maze[y][x] != 'W') return;	//已有编号或没有水 
	idx[y][x] = id;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(dirx[i] != 0 || diry[j] != 0)
				dfs(x+dirx[i],y+diry[j],id);	
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%s",maze[i]);
		memset(idx,0,sizeof(idx));
		int cnt = 0; //连通量编号
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(idx[i][j] == 0 && maze[i][j] == 'W') 
					dfs(j,i,++cnt);
		printf("%d\n",cnt);
	}
	return 0;
}
/*https://www.luogu.org/problem/P1596*/
/*
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

3
*/
