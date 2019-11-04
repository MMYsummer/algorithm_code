#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int a[105],b[105],c[105];

int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i];
	for(int i = 1;i<=n;i++)	//二维背包与一维背包优化为一维数组相似 
	{
		for(int j = m;j>=b[i];j--)
			for(int k = x;k>=c[i];k--)
				dp[j][k] = max(dp[j][k],dp[j-b[i]][k-c[i]]+a[i]);
	}
	cout<<dp[m][x]<<endl;
	return 0;
}
/*https://www.luogu.org/problem/P1910*/
/*
3 10 12
10 1 11
1 9 1
7 10 12

11
*/
