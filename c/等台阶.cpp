//假设有 N 层台阶，开始时你在第0层，每次你可以向上走至少1个至多 K 个台阶，请问走完这 N 个台阶共有多少种走法。





//递归 TLE 
#include<stdio.h>
#include<string.h>
//可得递推关系f(n) = f(n-1) + f(n-2) + f(n-3) + … + f( max(0,n-k) ) 

int N,k;

int max(int a,int b)
{
	return a>b?a:b;
	
}


int f(int n)
{int s=0;
if (0==n)return 1;//0也应视为一种情况，（可能存在由0直接到 n的情况（n<k)) 
if (1==n)return 1;//
for(int i=n-1;i>=max(0,n-k);i--)s+=(f(i));//max保证n<k的情况到0位置，不会出现负数 
	s%=10003;
	return s;	
}

int main()
{ 
scanf("%d %d",&N,&k);
N%=100003;
printf("%d",f(N));
return 0;
}





//递推 
//#include<stdio.h>
//#include<string.h>
//int N,K;
//int a[100005];
//int main()
//{
//	a[0] = 1;
//	scanf("%d %d",&N,&K);
//	for(int i = 1;i <= N;i++){
//		for(int j = 1;j <= K && i-j >= 0;j++){
//			a[i] += a[i-j];
//			a[i] = a[i]%100003;
//		}
//	}
//	printf("%d\n",a[N]);
//	return 0;
//} 	
	
	
   

