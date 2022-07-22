#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	int a[201],b[201];
	int n;
	scanf("%d",&n);

	int cnt=0;
	int N=n;
	while(N--) { //input

		scanf("%d %d",&a[cnt],&b[cnt]);
		cnt++;
	}
	for(int i=0; i<n-1; i++) {//maopao
		for(int j=n-1; j>i; j--)
			if(a[j]>a[j-1]||a[j]==a[j-1]&&b[j]<b[j-1]) {
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				t=b[j];
				b[j]=b[j-1];
				b[j-1]=t;
			
			}
	}
//output
	for(int i=0; i<n; i++) {
		int m=0;
		for(int j=0; j<i; j++) {
			if( a[j]>a[i]&&b[j]<b[i])m++;
		}
		printf("%d\n",m);
	}

	return 0;
}
