#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
int maze[maxn][maxn],maze_temp[maxn][maxn];
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};	//方向 
int n;

void dfs(int x,int y)	//x对应j y对应i 
{
	if(x<0 || x>n+1 || y<0 || y>n+1 || maze[y][x] != 0) return; //不符条件不搜 
	maze[y][x] = 1;		//染色 
	for(int i=0;i<4;i++)
		dfs(x+dir[i][0],y+dir[i][1]); 
	//不用回溯  
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(maze,0,sizeof(maze));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&maze[i][j]);
				maze_temp[i][j] = maze[i][j];
			}
			dfs(0,0);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(maze[i][j] == 0)
					printf("2 ");
				else
					printf("%d ",maze_temp[i][j]);
			}
			printf("\n");
		}	
	}			
	return 0;
}
/*
6
0 0 0 0 0 0 0 0		maze[0][]
0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0
0 0 1 1 0 0 1 0
0 1 1 0 0 0 1 0
0 1 0 0 0 0 1 0
0 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
*/
