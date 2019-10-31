#include <bits/stdc++.h>
using namespace std;

int v,g;	//ά�����������������
int vnums[30];	//ÿ��ά�������躬��
int gnums[30][30];	//ÿ����������ά���غ��� 
int fvnums[30];	//Ŀǰ�õ������к���ά�����ܺ��� 
int vis[30];	//ѡ�������ϼ�¼
int print[30];	//�����  
int mins = 999999;

void dfs(int step,int gid) //��ǰѡ����������gid�ӵ�ǰ��ŵ����Ͽ�ʼ���������ظ����� 
{
	if(step>=mins || step > g)	return;	//��ǰ���������ڵ��ڶ�����Ҫ����Ϊ�ж��ʱ���С���ֵ��� 
	int i;
	for(i=0;i<v;i++)
	{
		if(fvnums[i] < vnums[i])	//����δ�� 
			break; 
	}
	if(i==v)	//�������� 
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
			if(vis[j]==0)	//δ�� 
			{
				for(int k=0;k<v;k++)
					fvnums[k]+=gnums[j][k];	//��j��δȡ���ϵĵ�k��ά����
				vis[j] = 1;	
				dfs(step+1,j);
				for(int k=0;k<v;k++)
					fvnums[k]-=gnums[j][k];	//��j��δȡ���ϵĵ�k��ά����
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
