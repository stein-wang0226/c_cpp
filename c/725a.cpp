#include <stdio.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int min(int a,int b,int c) {
	if(a<=b&&a<=c)return a;
	else if(b<=a&&b<=c)return b;
	else return c;
}
int t,n,a[105],minp,maxp,p1,p2,mininum;
int main() {


	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);//input 
		}
		
		minp=1;
		maxp=1;
		for(int j=1; j<=n; j++) {
			if(a[j]>a[maxp]) maxp=j;
			if(a[j]<a[minp]) minp=j;
		}
		if(maxp<minp) {
			p1=maxp;
			p2=minp;
		} else {
			p1=minp;//p1 p2为前后两最值的位置 
			p2=maxp;
		}
	printf("%d\n",min(p2,n-p1+1,p1+n-p2+1));



	}
	return 0;
}
