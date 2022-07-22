#include<stdio.h>



int main() {
	int a[4],b[4],c[4],max,min,n;
	scanf("%d",&n);
	a[0]=n/1000;
	a[1]=n/100%10;
	a[2]=n/10%10;
	a[3]=n%10;
	int kabu=0;
	while(kabu!=6174) {
		for(int i=0; i<4; i++) {
			int k=i;
			for(int j=i+1; j<4; j++) {

				if(a[j]>a[k])k=j;
			}
			int t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
		max=a[0]*1000+a[1]*100+a[2]*10+a[3];
		min=a[3]*1000+a[2]*100+a[1]*10+a[0];
		kabu=max-min;
		printf("%d-%d=%04d\n",max,min,kabu);
		n=kabu;
		a[0]=n/1000;
		a[1]=n/100%10;
		a[2]=n/10%10;
		a[3]=n%10;
	}
	return 0;
}
