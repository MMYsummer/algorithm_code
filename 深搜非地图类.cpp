#include <bits/stdc++.h>
using namespace std;

int v,g;	//维生素种类和饲料种数
int vnums[30];	//每种维生素所需含量
int gnums[30][30];	//每种饲料所含维生素含量 
int fvnums[30];	//目前拿的饲料中含的维生素总含量 
int vis[30];	//选过的饲料记录
int print[30];	//输出用  
int mins = 999999;

void dfs(int step,int gid) //当前选的种类数，gid从当前编号的饲料开始搜索避免重复搜索 
{
	if(step>=mins || step > g)	return;	//当前饲料数大于等于都不想要，因为有多解时输出小的字典序 
	int i;
	for(i=0;i<v;i++)
	{
		if(fvnums[i] < vnums[i])	//饲料未够 
			break; 
	}
	if(i==v)	//结束条件 
	{
		mins = step;
		int k = 0;
		for(int j = 0;j<g;j++)
		{
			if(vis[j] == 1)
				print[k++] = j;
		}
	}
	else
	{
		for(int j = gid;j<g;j++)
		{
			if(vis[j]==0)	//未拿 
			{
				for(int k=0;k<v;k++)
					fvnums[k]+=gnums[j][k];	//第j号未取饲料的第k种维生素
				vis[j] = 1;	
				dfs(step+1,j);
				for(int k=0;k<v;k++)
					fvnums[k]-=gnums[j][k];	//第j号未取饲料的第k种维生素
				vis[j] = 0;	
			}
		}
	}
}

int main()
{
	scanf("%d",&v);
	for(int i=0;i<v;i++)
		scanf("%d",&vnums[i]);
	scanf("%d",&g);
	for(int i=0;i<g;i++)
		for(int j=0;j<v;j++)
			scanf("%d",&gnums[i][j]);
	dfs(0,0);
	printf("%d",mins);
	for(int i=0;i<mins;i++)
		printf(" %d",print[i]+1);
	printf("\n");
	return 0;
}
/*https://www.luogu.org/problem/P1460*/
/*
4
100 200 300 400
3
50  50  50  50
200 300 200 300
900 150 389 399

2 1 3

*/
