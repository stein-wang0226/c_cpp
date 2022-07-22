#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	int n ,t;
	long long a[301],b[301];
	scanf("%d",&t);
	for (int i=0; i<t; i++) { //input
		n=0;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int j=0; j<n; j++)
			scanf("%lld",&a[j]);
		int cnt;//´¦Àí
		for(int k=0; k<(n+1)/2; k++) {
			b[2*k]=a[k];
			cnt=k;
		}
		if(n%2) {//ou
			for(int m=0; m<n/2; m++) {
				b[n-2-2*m]=a[cnt+1+m];
			}
		}
		else{
			for(int m=0; m<n/2; m++) {
				b[n-1-2*m]=a[cnt+1+m];
			}
		}
		for(int m=0; m<n; m++)
			printf("%lld ",b[m]);
		printf("\n");
	}

	return 0;
}
