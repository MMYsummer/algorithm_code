#include <bits/stdc++.h>
using namespace std;

int dp[200][10005];
int v[200];	//��˵ļ۸�,�±����
 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dp[1][v[1]] = 1;	//�������϶��£�������������ʼ��
	for(int j = 1;j<=m;j++)
	{
		for(int i = 2;i<=n;i++)
		{
			if(j>v[i])
				dp[i][j] = dp[i-1][j]+dp[i-1][j-v[i]];
			if(j==v[i])
				dp[i][j] = dp[i-1][j]+1;
			if(j<v[i])
				dp[i][j] = dp[i-1][j];
		}	
	}
	printf("%d\n",dp[n][m]);
	return 0;
}
/*
״̬ת�Ʒ��� 
j>vi:dp[i][j] = dp[i-1][j]+dp[i-1][j-vi]				
j=vi:dp[i][j] = dp[i-1][j]+1				
j<vi:dp[i][j] = dp[i-1][j]	
id	v	0	1	2	3	4
1	1	0	2	3	4	3
2	1	0	1	2	2	1
3	2	0	0	2	0	1
4	2	0	0	1	0	0
�Ե����ϣ���������						
id	v	0	1	2	3	4
1	1	0	1	0	0	0
2	1	0	2	1	0	0
3	2	0	2	2	2	1
4	2	0	2	3	4	3
���϶��£���������						
*/
/*https://www.luogu.org/problem/P1164*/
/*
4 4
1 1 2 2

3
*/
