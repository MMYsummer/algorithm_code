#include <bits/stdc++.h>/*https://www.luogu.org/problem/P1434	���仯����*/
using namespace std;

int d[105][105];	//ĳ������о���  
int maze[105][105];	//��ͼ	 
int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0}};	//���� 
int n,m;	//���� 
int maxn;	//ĳ�����ֵ��¼ 

void dfs(int r,int c,int step);	//���ѣ����л��г��� 

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&maze[i][j]);
	int maxs = 1;	//����ͼ������о���ֵ 
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			maxn = 0;
			dfs(i,j,1);	//��ʼ��Ҳ��1���� 
			d[i][j] = maxn;
			maxs = max(maxs,maxn);	//��¼���е�����ĵ� 
		}
	printf("%d\n",maxs);
	return 0;
}

void dfs(int r,int c,int step)
{
	if(d[r][c] != 0)	//�Ѿ��ҳ�����о�������Ҫ���ظ����� ��֦���� 
	{
		maxn = max(maxn,d[r][c]+step-1);	//-1����Ϊ���ظ��㵱ǰ�� 
		return;
	}
	maxn = max(maxn,step);	//��¼��������� 
	for(int i=0;i<4;i++)
	{
		int dr = r + dir[i][0];
		int dc = c + dir[i][1];
		if(dr>=0 && dr<n && dc>=0 && dc<m && maze[r][c]>maze[dr][dc])	//δԽ����Ϊ�»��� 
		{
			dfs(dr,dc,step+1);	
		} 
	}
}
/*
�������룺
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

���������
25
 
*/
