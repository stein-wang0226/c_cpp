#include<stdio.h>
int main(){int a,b,m=0;
	scanf("%d",&a);
	b=a;//储存a原始值 
	if (a<0)printf("No");
	else
	{
	
		while(a>0)
		{
		m=m*10+a%10;//回文数转换 
		a/=10;//
		}
		//printf("%d %d",a,m);
			if(b==m)printf("Yes");
			else printf("No");	
	
	}
	
	
	

	
	return 0;
	
}
