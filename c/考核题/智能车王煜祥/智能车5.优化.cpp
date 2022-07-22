//类似桶排序 ，将每位的值作下标来检查重复，巧妙
# include <bits/stdc++.h>
using namespace std;
int main() {
	int x,a[9],m[10],s,t;//ps：之前m下标越界导致b的值错误 :(

	int A,B,C;
	cin>>A>>B>>C;
	for(x=100; x<1000; x++) {
		if(!(x*B%A)&&!(x*C%A)&&x*B/A>100&&x*C/A>100) {
			a[0]=x%10;
			a[1]=x/10%10;
			a[2]=x/100;
			a[3]=x*B/A%10;
			a[4]=x*B/A/10%10;
			a[5]=x*B/A/100;
			a[6]=x*C/A%10;
			a[7]=x*C/A/10%10;
			a[8]=x*C/A/100;
			for(int i=0; i<10; i++)m[i]=0 ;
			for(int i=0; i<9; i++)  m[a[i]]=1;
			s=0;
			for(t=1; t<=9; t++) s+=m[t];
			if(s==9) {
				printf("%d %d %d\n",x,2*x,3*x);
			}
		}
	}
	return 0;
}
