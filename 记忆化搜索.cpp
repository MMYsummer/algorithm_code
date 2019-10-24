#include <bits/stdc++.h>/*https://www.luogu.org/problem/P1434	记忆化搜索*/
using namespace std;

int d[105][105];	//某点最长滑行距离  
int maze[105][105];	//地图	 
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};	//方向 
int n,m;	//行列 
int maxn;	//某点最大值记录 

void dfs(int r,int c,int step);	//深搜，行列滑行长度 

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&maze[i][j]);
	int maxs = 1;	//整个图中最长滑行距离值 
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			maxn = 0;
			dfs(i,j,1);	//起始点也算1步数 
			d[i][j] = maxn;
			maxs = max(maxs,maxn);	//记录所有点中最长的点 
		}
	printf("%d\n",maxs);
	return 0;
}

void dfs(int r,int c,int step)
{
	if(d[r][c] != 0)	//已经找出最长滑行距离则不需要再重复搜索 剪枝条件 
	{
		maxn = max(maxn,d[r][c]+step-1);	//-1是因为会重复算当前点 
		return;
	}
	maxn = max(maxn,step);	//记录滑行最长距离 
	for(int i=0;i<4;i++)
	{
		int dr = r + dir[i][0];
		int dc = c + dir[i][1];
		if(dr>=0 && dr<n && dc>=0 && dc<m && maze[r][c]>maze[dr][dc])	//未越界且为下滑点 
		{
			dfs(dr,dc,step+1);	
		} 
	}
}
/*
样例输入：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

样例输出：
25
 
*/
