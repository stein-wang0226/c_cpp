#include<stdio.h>
#include<string.h>
#include<math.h>
long long sum(int a){
	long long cnt=0;
	for(int i=1;i<=a;i++)
	cnt+=i*(a+1-i);
	return cnt;
}
int main() {
	long long N;
    int a,left;
    scanf("%lld",&N);
    int t=1;
   // printf("%lld",sum(3));
    while(sum(t)<=N)t++;
	a=--t;
	left=N-sum(a);
	printf("%d\n%d",a,left);
	return 0;
}
