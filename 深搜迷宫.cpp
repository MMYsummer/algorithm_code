#include <bits/stdc++.h>
using namespace std;

int maze[20][20],n,m;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};//���� 
int minn; 
char bu[200][6],temp[200][6]; 	//��ÿһ�� 

void dfs(int x,int y,int count);

int main()
{	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&maze[i][j]);
		minn = 999999; //��ʼ�����·�� 
		dfs(0,0,0);
//		printf("%d\n",minn+2);
		printf("(0,0)\n");
		for(int i=0;i<minn;i++)
			printf("%s\n",bu[i]);
		printf("(%d,%d)\n",n-1,m-1);
	}
	return 0;
}

void dfs(int x,int y,int count)
{
	for(int i=0;i<4;i++)
	{
		int tx = x+dx[i];
		int ty = y+dy[i];
		if(tx>=0&&ty>=0&&tx<n&&ty<m&&(maze[tx][ty]==0))	//�ж��Ƿ�Խ�����Ƿ����
		{
			if(tx==n-1 && ty==m-1)
			{
				if(count<minn)
				{
					minn = count;
					for(int j = 0;j<minn;j++)
					{
						strcpy(bu[j],temp[j]);	
					}	
				} 
			}
			else
			{
				maze[tx][ty] = 1;
				temp[count][0]= '(';
				temp[count][1]= tx+'0';
				temp[count][2]= ',';
				temp[count][3]= ty+'0';
				temp[count][4]= ')';
				dfs(tx,ty,count+1);
				maze[tx][ty] = 0;
			}
		} 
	}
}
