#include<stdio.h>
#include<string.h>

int main(){
	long long x,p ,m,t=0,xi,r=1,ans;//r储存p奇数时单个乘积 ,xi储存每次平方后的值
	scanf("%d%d%d",&x,&p,&m);
	xi=x;
	while(p>1){//ou
		
		{if((p%2))r=r*xi%m;
		   p/=2;
		   xi=xi*xi%m; 
		   
		}
		
	}
		ans=xi*r%m;	
	printf("%d",ans);
 	return 0;
}


////递归快速幂（对大素数取模）
//#define MOD 1000000007
//typedef long long ll;
//ll qpow(ll a, ll n)
//{
//    if (n == 0)
//        return 1;
//    else if (n % 2 == 1)
//        return qpow(a, n - 1) * a % MOD;
//    else
//    {
//        ll temp = qpow(a, n / 2) % MOD;
//        return temp * temp % MOD;
//    }
//}
