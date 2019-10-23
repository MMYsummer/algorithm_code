#include <bits/stdc++.h>
using namespace std;

int num[1000000];
int h[1000000];
int l[1000000];

void bigorlit(int n);

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		for(int i = 1;i<=n;i++)
			scanf("%d",&num[i]);
		bigorlit(n);//标记第几大和第几小 
		int min = 9999999;
		for(int i = 1;i<=n;i++)
		{
			int sum = n-(h[i]+l[i]-1);
			if(sum<min)
				min = sum;
		}
		printf("%d\n",min);	
	}
	return 0;
}

void bigorlit(int n)
{
	h[1] = 1;
	l[n] = 1;
	for(int i = 2;i<=n;i++)	
	{
		h[i] = 1;
		int max = 1;
		for(int k = 1;k<i;k++)
		{
			if(num[i]>num[k] && h[k]>=max)
				max = h[k]+1;
		}
		h[i] = max;
			
		l[n-i+1] = 1;
		int min = 1;
		for(int k = n;k>n-i+1;k--)
		{
			if(num[n-i+1]>num[k] && l[k]>=min)
				min = l[k]+1;
		}
		l[n-i+1] = min;
	}
}

/*
186 186 150 200 160 130 197 200
1	1	1	2	2	1	3	4	//大 
3	3	2	3	2	1	1	1	//小	
https://www.nowcoder.com/practice/6d9d69e3898f45169a441632b325c7b4?tpId=37&tqId=21247&tPage=2&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
*/
