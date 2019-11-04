#include <bits/stdc++.h>
using namespace std;

int dp[30][30005];	//采用 自底向上，自左向右 填表 
struct{
	int v;
	int p;
}M[30];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>M[i].v>>M[i].p;
	for(int i=1;i<=n;i++)
	{
		if(i>=M[m].v)
			dp[m][i] = M[m].v*M[m].p;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=m-1;i>=1;i--)
		{
			if(j-M[i].v>=0)	//如果当前钱数可以装	 
				dp[i][j] = max(dp[i+1][j-M[i].v]+M[i].p*M[i].v,dp[i+1][j]);
			else
				dp[i][j] = dp[i+1][j];
		}	
	}
	cout<<dp[1][n]<<endl;	
	return 0;
}
/*
https://www.luogu.org/problem/P1060
*/
/*
1000 5
800 2
400 5
300 5
400 3
200 2

3900
*/
