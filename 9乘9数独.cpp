#include <bits/stdc++.h>
using namespace std;

char maze[15][15];	//数独图 
int flag;	//判定,当pd等于81时表示数独已解 
int han[15][15],lie[15][15]; //判定某个数字在对应的行列是否已经存在  
int gong[10][10];	//判断宫内是否存在某个数字 
void dfs(int x,int y)
{
	if(flag == 81)
	{
		printf("\n");
		for(int i=0;i<9;i++)
			printf("%s\n",maze[i]);
	}
	else
	if(x<9 && x>=0 && y<9 && y>=0)
	{
		if(maze[y][x] == '0')	//如果此格未填 
		{
			for(int i=1;i<=9;i++)
			{
				int o = 3*(y/3)+x/3+1;	//算所在宫 
				if(han[y][i]!=1 && lie[x][i] != 1 && gong[o][i] !=1)	//行列和宫不存在此数字则尝试填入数字 
				{
					maze[y][x] = i+'0';
					han[y][i] = 1;
					lie[x][i] = 1;
					gong[o][i] = 1;
					flag++;
					if(x==8) //该换行了
						dfs(0,y+1);
					else
						dfs(x+1,y); 
					maze[y][x] = '0';
					han[y][i] = 0;
					lie[x][i] = 0;
					gong[o][i] = 0;
					flag--;
				}
			}
		}
		else
		{
			if(x==8)
				dfs(0,y+1);
			else
				dfs(x+1,y); 
		}	
	}
}

int main()
{
	flag = 0;
	for(int i=0;i<9;i++)
		scanf("%s",maze[i]);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			if(maze[i][j]!='0')
			{	
				flag++;
				han[i][maze[i][j]-'0'] = 1; //第i行存在数字 maze[i][j];
				lie[j][maze[i][j]-'0'] = 1;
				int o = 3*(i/3)+j/3+1;	//算所在宫  
				gong[o][maze[i][j]-'0'] = 1;
			}		
		}
	dfs(0,0);
	return 0;
}
/*
005300000
800000020
070010500
400005300
010070006
003200080
060500009
004000030
000009700
*/

/*
1 4 5 3 2 7 6 9 8
8 3 9 6 5 4 1 2 7
6 7 2 9 1 8 5 4 3
4 9 6 1 8 5 3 7 2
2 1 8 4 7 3 9 5 6
7 5 3 2 9 6 4 8 1
3 6 7 5 4 2 8 1 9
9 8 4 7 6 1 2 3 5
5 2 1 8 3 9 7 6 4
*/

/*
064305000
000709030
509000086
010900360
040050071
053006020
190000607
000502000
000607140
*/

/*
764385219
821769534
539421786
217948365
648253971
953176428
192834657
476512893
385697142
*/
