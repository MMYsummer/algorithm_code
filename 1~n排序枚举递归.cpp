#include <bits/stdc++.h>
using namespace std;

void p(int n,int *num,int cur)	//1~n按字典序排列  
{
	if(cur==n)	//当前位置为n时结束递归  
	{
		for(int i=0;i<n;i++)
			printf("%5d",num[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1;i<=n;i++)	//测试1~n还有哪个数组可以填 
		{
			int ok = 1;
			for(int j=0;j<cur;j++)	//检测数字i是否已经在序列中 
				if(num[j]==i) ok = 0;
			if(ok)
			{
				num[cur] = i;
				p(n,num,cur+1);	
			}
		}
	}
}

int main()
{
	int num[1000],n;
	while(scanf("%d",&n)!=EOF)
	{
		p(n,num,0);
	}
	return 0;
}
