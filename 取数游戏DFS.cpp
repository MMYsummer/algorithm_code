#include <bits/stdc++.h>
using namespace std;

int maze[100][100];	//ͼ 
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};	//���� 
int n,m;//���� 
int vis[100][100];	//����Ƿ���ѡ 
int maxs = 0;
void  visf(int r,int c,int o)	//��ȡ�����˸�������Ϊ����ѡ��λ  
{
	vis[r][c] += o;
	for(int i=0;i<8;i++)
	{
		if(r>0 && r<=n && c>0 && c<=m)	//δԽ�� 
		{
			vis[r+dir[i][0]][c+dir[i][1]] += o;	//��� ��+=Ϊ�˸�λʱ���Ὣ֮ǰ��ѡ�Ĵ�������� 
		}
	}
}

void dfs(int r,int c,int ans)
{
	maxs = max(maxs,ans);
	int dc = c+1,dr = r;
	if(dc>m)	//���� 
	{
		dr++;
		dc = 1;
		if(dr>n) return;	//Խ�� 
	}
	if(vis[dr][dc]==0)	//δȡ
	{
		visf(dr,dc,1);	 
		dfs(dr,dc,ans+maze[dr][dc]);
		visf(dr,dc,-1);	
	}
	dfs(dr,dc,ans);	//��ѡ 
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
