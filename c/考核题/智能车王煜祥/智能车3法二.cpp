

# include <string.h>
#include<stdio.h>
int main(){
	int a,b,c,d,e;
	scanf("%d",&a);
	if(a>0){
	while(a>0){
		b=a%10;
		c=c*10+b;
		a/=10;}printf("%d",c);}	


	else{d=(-a);
	while(d>0){	
	b=d%10;
		c=c*10+b;
		d/=10;}
		printf("%d",-c);
	}
	return 0;
	}
