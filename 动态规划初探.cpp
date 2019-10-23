#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int calStringDistance(string a,string b)
{
	int n = a.length();
	int m = b.length();
	if(n == 0) return m;	//其中一字符串为空则需要操作另一个字符串长度此 
	if(m == 0) return n;
	for(int i=0;i<=n;i++)	//初始化结果数组，有空串得来  
		dp[i][0] = i;
	for(int i=1;i<=m;i++)
		dp[0][i] = i;
	for(int i=1;i<=n;i++)		//从（1,1）开始遍历每个子问题的最优解  
		for(int j=1;j<=m;j++)
		{
			if(a[i-1] == b[j-1]) 	//若子串最后一个不相等，则同长度子串操作增加一次 
			{
				dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1]+1,dp[i-1][j]+1));
			}
			else
			{
				dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
			}
		}
	return dp[n][m];
}

int main()
{
	string a,b;
	while(cin>>a>>b)
		cout<<calStringDistance(a,b)<<endl;
	return 0;
}
/*
https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&tqId=21275&tPage=3&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
*/
/*
	（1）设可以在k1个操作内将s[0：i-1]转换为t[0：j]，用k1+1次操作将s[0：i]转化为t[0：j]，只需要先在“s[0：i]转化为t[0：j]”的操作开端做1次移除操作移除s[i]将s[0:i]转化为s[0:i-1]，然后再做k1个操作就可以转换为t[0:j]。对应表格，既矩阵所求d[i][j]的左格。
			
	（2）设可以在k2个操作内将s[0：i]转换为t[0：j-1]，用k2+1次操作将s[0：i]转化为t[0：j]，先用k2次操作将s[0:i]转化为t[0：j-1]，然后再执行1次插入操作在“s[0:i]变成t[0：j-1]的操作”的末尾插入“增加t[j]”的一次操作，即可将s[0:i]转化为t[0:j]。对应表格，既矩阵所求d[i][j]的上格。

	（3）设可以在k3个操作内将s[0：i-1]转化为t[0：j-1] ，若s[i]==t[j]，S[0:i]变到t[0:j]就只要k3个操作，若s[i]！=t[j]，则需1次换操作加在s[0：i-1]转化为t[0：j-1]的操作数基础上就可以将S[0:i]变到t[0:j]，共k3+1次。对应所求d[i][j]的左上格。
		俩子字符串长度相等时  
*/
