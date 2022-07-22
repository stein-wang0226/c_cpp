#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	int  a[201],b[201],n,j;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=0; i<n; i++) {
		int s=i;
		for(j=i; j<n ; j++) {
			if((a[j]>a[s])||a[j]==a[s]&&b[j]<b[s])
				s=j;
		}
		int t=a[s];
		a[s]=a[i];
		a[i]=t;
		 t=b[s];
		b[s]=b[i];
		b[i]=t;
	}
	for(int i=0; i<n; i++) {
		int cnt=0;
		for(j=0; j<i ; j++) {

			if(b[j]<b[i])cnt++;
		}
		printf("%d\n",cnt);

	}
	return 0;
}
