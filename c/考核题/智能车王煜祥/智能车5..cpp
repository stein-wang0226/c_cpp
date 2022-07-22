
# include <string.h>
#include<stdio.h>
int main() {

	int A,B,C,a[9];
	cin>>A>>B>>C;
	for(A=123; A<333; A++) {
		B=A*2;
		C=A*3;
		a[0]=A%10;
		a[1]=A/10%10;
		a[2]=A/100;
		a[3]=B%10;
		a[4]=B/10%10;
		a[5]=B/100;
		a[6]=C%10;
		a[7]=C/10%10;
		a[8]=C/100;
		if(a[1]+a[2]+a[0]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]==45&&(a[1]*a[2]*a[0]*a[3]*a[4]*a[5]*a[6]*a[7]*a[8]==362880)) {
			printf("%d %d %d\n",A,B,C);
		}


	}
	return 0;
}
