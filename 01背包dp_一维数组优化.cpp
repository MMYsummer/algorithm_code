#include <bits/stdc++.h>
using namespace std;

int dp[12881];
struct{
	int c;	//重量 
	int w;	//价值 
}g[3403];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)
		scanf("%d%d",&g[i].c,&g[i].w);
	for(int i = 1;i<=n;i++)
	{
		for(int j=m;j>=g[i].c;j--)	//必须逆序 
		{
			dp[j] = max(dp[j-g[i].c]+g[i].w,dp[j]);
		}
	}
	printf("%d\n",dp[m]);
	return 0;
}
/*https://www.luogu.org/problem/P2871*/
/*
4 6
1 4
2 6
3 12
2 7

23
*/
