#include <bits/stdc++.h>
using namespace std;
/*
����˼��  
���ɣ����������ݽ��ʵ���Ͼ����ڱ仯���������е�ָ��Ϊ����ʱ�����ĳ˻���
����汾 
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            //���ָ��Ϊż��
            power = power / 2;//��ָ����СΪһ��
            base = base * base % 1000;//��������ԭ����ƽ�� 
        } else {
            //���ָ��Ϊ����
            power = power - 1;//��ָ����ȥ1��ʹ����һ��ż��
            result = result * base % 1000;//��ʱ�ǵ�Ҫ��ָ��Ϊ����ʱ��������ĵ�����һ�η��ռ���
            power = power / 2;//��ʱָ��Ϊż�������Լ���ִ�в���
            base = base * base % 1000;
        }
    }
    return result;
}

�Ż��� 
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

�ռ��Ż� 
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//�˴��ȼ���if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1;//�˴��ȼ���power=power/2
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
		if(p%2==1)	//ָ��Ϊ����
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

3. ( a �C b ) % c = ( ( a % c ) �C ( b % c ) ) % c
*/
/*
3^10=9^5
9^5=��9^4��*��9^1��
9^5=��81^2��*(9^1)
9^5=��6561^1��*(9^1)
���ɣ����������ݽ��ʵ���Ͼ����ڱ仯���������е�ָ��Ϊ����ʱ�����ĳ˻���
*/
