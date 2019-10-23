#include <bits/stdc++.h>
using namespace std;

int N;
int maze[15][15];//��� 
int counts = 0;//������� 
int flag = 0;//����ֻ���ǰ������  
int Lie[15]={0};
int s[15]={0},k=0;

int  dj(int x,int y)
{
	int i=x,j=y;
	while(i<=N && j<=N) //���½��ҶԽ��� 
	{
		if(maze[i][j]==1)
		return 0;
		i++;j++;
	}
	
	i=x;j=y;
	while(i>=1 && j<=N) //���½��ҶԽ��� 
	{
		if(maze[i][j]==1)
		return 0;
		i--;j++;
	}
	
	i=x;j=y;
	while(i<=N && j>=1) //���Ͻ��ҶԽ��� 
	{
		if(maze[i][j]==1)
		return 0;
		i++;j--;
	}
	
	i=x;j=y;
	while(i>=1 && j>=1) //���Ͻ��ҶԽ��� 
	{
		if(maze[i][j]==1)
		return 0;
		i--;j--;
	}
	return 1;
}

void dfs(int y)
{
		if(y>N)	//�Ѿ��ų�һ�ֽ�  
		{
			counts++;
			if(flag<3)
			{
				for(int i=0;i<N;i++)
					printf("%d ",s[i]);
				printf("\n");
				flag++;
			}
			return;
		}
		for(int i=1;i<=N;i++)
			if(Lie[i]==0 && dj(i,y))	//����ԽǶ��� 
			{
				maze[i][y] = 1;
				Lie[i] = 1;
				s[k++] = i;
				dfs(y+1);	//��һ�� 
				maze[i][y] = 0;
				Lie[i] = 0;
				s[--k] = 0;
			}
}

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		memset(maze,0,sizeof(maze));	//��ʼ�� 
		memset(Lie,0,sizeof(Lie));
		counts = flag =0;
		dfs(1);
		printf("%d\n",counts);
	}
	return 0;
}
