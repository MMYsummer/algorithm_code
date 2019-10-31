#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int x,y;
}P;

int maze[10][10];	//地图 
int d[10][10];	//某点到起点距离 
bool b[10][10];	//判断某点是否已经入队
queue<P> que;	//队列，存要进行计算的点 
int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};	//方向
int n; 	//地图大小 

void bfs(int x,int y,int step)
{
	d[x][y] = step;
	b[x][y] = false;
	P p;
	p.x = x;
	p.y = y;
	que.push(p);	//起点入队
	while(que.size())
	{
		P t = que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int dx = t.x + dir[i][0];
			int dy = t.y + dir[i][1];
			if(dx<0 || dx>=n || dy<0 || dy>=n)	continue;
			if(b[dx][dy])	//未被计算
			{
				p.x = dx;
				p.y = dy;
				que.push(p);	//符合入队 
				b[dx][dy] = false;	//表示已经入队 
				d[dx][dy] = d[t.x][t.y] + 1;	//在上个节点距离加1 
			} 
		}
	} 
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&maze[i][j]);
	memset(d,-1,sizeof(d));
	memset(b,true,sizeof(b));
	bfs(0,0,0);
	printf("%d\n",d[n-1][n-1]);
	return 0;
}
/*	不算起点为一步 
Sample Input
5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
Sample Output
8

*/
