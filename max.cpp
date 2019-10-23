#include<stdio.h>

int max_a_b(int *a,int *b,int a_len,int b_len)
{
//	printf("a1.len = %d\ta2.len = %d\n",a_len,b_len);
	int f = 1,F = 1;
	int a1[a_len],a2[a_len],b1[b_len],b2[b_len],a1_num = 0,a2_num = 0,b1_num = 0,b2_num = 0;
	for(int i = 0;i<a_len-1;i++)
	{
		if(a[i]<=a[i+1]) 
		{
			f++;
		}
		else
		{
			for(int j = 0,q = 0;j<a_len;j++)
			{
				if(a[j]>a[i+1]&&j<(i+1)) 
				{
					a1_num ++;
					continue;
				}
				else {
					a1[q] = a[j];
					q++;
				}	
			}
			for(int j = 0,p = 0;j<a_len;j++)
			{
				if(a[j]<a[i]&&j>i) 
				{
				    a2_num ++;
				    continue;
				}
				else{
				    a2[p] = a[j];
				    p++;
				}
			}
	    	f = max_a_b(a1,a2,a_len-a1_num,a_len-a2_num);
		    break;
		}
	}
	for(int i = 0;i<b_len-1;i++)
	{
		if(b[i]<=b[i+1]) 
		{
			F++;
		}
		else
		{
			for(int j = 0,q = 0;j<b_len;j++)
			{
				if(b[j]>b[i+1]&&j<i+1)
				{
					b1_num ++;
					continue;
				}
				else
				{
					b1[q] = b[j];
					q++;
				}
			}
			for(int j = 0,q = 0;j<b_len;j++)
			{
				if(b[j]<b[i]&&j>i)
				{
					b2_num ++;
					continue;
				}
				else
				{
					b2[q] = b[j];
					q++;
				}
			}
			F = max_a_b(b1,b2,b_len-b1_num,b_len-b2_num);
		    break;
		}
	}
    return f>=F?f:F;
}

int main()
{
	int a[30000],b[5] = {3,2,1},c,i,N;
	char ch;
	while(scanf("%d",&N)!=EOF)
	{
		for(i = 0;i<N;i++)
		{
		scanf("%d",&a[i]);
		ch = getchar();
		if(ch == '\n') break;	
	    }
	    c = max_a_b(a,b,N,3);
	    printf("up.len = %d\n",c);  
	}
	return 0;
}
