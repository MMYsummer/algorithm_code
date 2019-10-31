#include <bits/stdc++.h>
using namespace std;
/*
核心思想  
规律：最后求出的幂结果实际上就是在变化过程中所有当指数为奇数时底数的乘积。
最初版本 
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            //如果指数为偶数
            power = power / 2;//把指数缩小为一半
            base = base * base % 1000;//底数变大成原来的平方 
        } else {
            //如果指数为奇数
            power = power - 1;//把指数减去1，使其变成一个偶数
            result = result * base % 1000;//此时记得要把指数为奇数时分离出来的底数的一次方收集好
            power = power / 2;//此时指数为偶数，可以继续执行操作
            base = base * base % 1000;
        }
    }
    return result;
}

优化版 
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base % 1000;
        }
        power = power / 2;
        base = (base * base) % 1000;
    }
    return result;
}

终极优化 
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 1000;
    }
    return result;
}


*/
long int fastp(long int b,long int p,long int k)
{
	long int re = 1;
	if(p==0) return 1%k;
	while(p)
	{
		if(p%2==1)	//指数为奇数
		{
			re = (re*b)%k;	
		}
		p/=2;
		b = (b*b)%k;	
	}
	return re;
}

int main()
{
	long int b,p,k;
	cin>>b>>p>>k;	
	printf("%ld^%ld mod %ld=%ld\n",b,p,k,fastp(b,p,k))	;
	return 0;
}
/*
1. ( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c

2. ( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c

3. ( a – b ) % c = ( ( a % c ) – ( b % c ) ) % c
*/
/*
3^10=9^5
9^5=（9^4）*（9^1）
9^5=（81^2）*(9^1)
9^5=（6561^1）*(9^1)
规律：最后求出的幂结果实际上就是在变化过程中所有当指数为奇数时底数的乘积。
*/
