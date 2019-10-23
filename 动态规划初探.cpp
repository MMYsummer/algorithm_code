#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int calStringDistance(string a,string b)
{
	int n = a.length();
	int m = b.length();
	if(n == 0) return m;	//����һ�ַ���Ϊ������Ҫ������һ���ַ������ȴ� 
	if(m == 0) return n;
	for(int i=0;i<=n;i++)	//��ʼ��������飬�пմ�����  
		dp[i][0] = i;
	for(int i=1;i<=m;i++)
		dp[0][i] = i;
	for(int i=1;i<=n;i++)		//�ӣ�1,1����ʼ����ÿ������������Ž�  
		for(int j=1;j<=m;j++)
		{
			if(a[i-1] == b[j-1]) 	//���Ӵ����һ������ȣ���ͬ�����Ӵ���������һ�� 
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
	��1���������k1�������ڽ�s[0��i-1]ת��Ϊt[0��j]����k1+1�β�����s[0��i]ת��Ϊt[0��j]��ֻ��Ҫ���ڡ�s[0��i]ת��Ϊt[0��j]���Ĳ���������1���Ƴ������Ƴ�s[i]��s[0:i]ת��Ϊs[0:i-1]��Ȼ������k1�������Ϳ���ת��Ϊt[0:j]����Ӧ��񣬼Ⱦ�������d[i][j]�����
			
	��2���������k2�������ڽ�s[0��i]ת��Ϊt[0��j-1]����k2+1�β�����s[0��i]ת��Ϊt[0��j]������k2�β�����s[0:i]ת��Ϊt[0��j-1]��Ȼ����ִ��1�β�������ڡ�s[0:i]���t[0��j-1]�Ĳ�������ĩβ���롰����t[j]����һ�β��������ɽ�s[0:i]ת��Ϊt[0:j]����Ӧ��񣬼Ⱦ�������d[i][j]���ϸ�

	��3���������k3�������ڽ�s[0��i-1]ת��Ϊt[0��j-1] ����s[i]==t[j]��S[0:i]�䵽t[0:j]��ֻҪk3����������s[i]��=t[j]������1�λ���������s[0��i-1]ת��Ϊt[0��j-1]�Ĳ����������ϾͿ��Խ�S[0:i]�䵽t[0:j]����k3+1�Ρ���Ӧ����d[i][j]�����ϸ�
		�����ַ����������ʱ  
*/
