#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int x,y;
}P;

int maze[10][10];	//��ͼ 
int d[10][10];	//ĳ�㵽������ 
bool b[10][10];	//�ж�ĳ���Ƿ��Ѿ����
queue<P> que;	//���У���Ҫ���м���ĵ� 
int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};	//����
int n; 	//��ͼ��С 

void bfs(int x,int y,int step)
{
	d[x][y] = step;
	b[x][y] = false;
	P p;
	p.x = x;
	p.y = y;
	que.push(p);	//������
	while(que.size())
	{
		P t = que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			int dx = t.x + dir[i][0];
			int dy = t.y + dir[i][1];
			if(dx<0 || dx>=n || dy<0 || dy>=n)	continue;
			if(b[dx][dy])	//δ������
			{
				p.x = dx;
				p.y = dy;
				que.push(p);	//������� 
				b[dx][dy] = false;	//��ʾ�Ѿ���� 
				d[dx][dy] = d[t.x][t.y] + 1;	//���ϸ��ڵ�����1 
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
/*	�������Ϊһ�� 
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
