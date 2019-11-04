#include <bits/stdc++.h>
using namespace std;

int dp[35][20005];

int main()
{
	int v,n,goods[35];
	scanf("%d%d",&v,&n);
	for(int i = 1;i<=n;i++)
		scanf("%d",&goods[i]);
	for(int j = goods[1];j<=v;j++)	//³õÊ¼»¯ 
		dp[1][j] = goods[1];
	for(int j = 1;j<=v;j++)
	{
		for(int i=2;i<=n;i++)
		{
			if(j<goods[i])
				dp[i][j] = dp[i-1][j];
			if(j==goods[i])
				dp[i][j] = max(dp[i-1][j],goods[i]);
			if(j>goods[i])
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-goods[i]]+goods[i]);
		}
	}
	printf("%d\n",v-dp[n][v]);
	return 0;
}
/*https://www.luogu.org/problem/P1049*/
/*
24
6
8
3
12
7
9
7

0
*/
