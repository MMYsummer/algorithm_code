#include <bits/stdc++.h>
using namespace std;

void p(int n,int *num,int cur)	//1~n���ֵ�������  
{
	if(cur==n)	//��ǰλ��Ϊnʱ�����ݹ�  
	{
		for(int i=0;i<n;i++)
			printf("%5d",num[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1;i<=n;i++)	//����1~n�����ĸ���������� 
		{
			int ok = 1;
			for(int j=0;j<cur;j++)	//�������i�Ƿ��Ѿ��������� 
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
