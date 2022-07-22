#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long i;
		int n;//总数存为n
		scanf("%lld",&i);
	                       // 遍历寻找会超时
			int cnt=0;
			long long i1=i ;//以防改变i1 
			while (i1) { //计算位数cnt
				i1/=10;
				cnt++;
			}
			n=(cnt-1)*9;//先算出该位以内所有情况,
			long long k=0;
			while(cnt--) { //算出该位对应的 cnt个1的数 
				k=k*10+1;
			}
			n+=i/k;

		
		printf("%d\n",n);
	}
	return 0;



}
