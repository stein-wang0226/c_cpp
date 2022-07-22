#include<stdio.h>
#include<string.h>
int a[4],m,h,m1,h1;//m1，h1为镜像 
int H,M;
int ishf(){//判断合法 
	for(int i=0;i<4;i++){
		if(a[i]==0||a[i]==1||a[i]==2||a[i]==5||a[i]==8) continue;
		else return 0;	
	}
	if(h1>=H||m1>=M) return 0;
	return 1;
}

int main(){
	scanf("%d %d",&H,&M);
	scanf("%d:%d",&h,&m); 
	a[0]=h/10;a[1]=h%10;a[2]=m/10;a[3]=m%10;
//	printf("%d %d\n",h,m); 
	for(int i=0;i<4;i++){
		if(2==a[i])a[i]=5;
		else if(5==a[i])a[i]=2;
	}
	m1=a[1]*10+a[0];h1=a[3]*10+a[2];
//	printf("%d %d",h1,m1); 
	while(!ishf()){//每次加一分钟判断 
		m=(m+1)%M;
		if(0==m)h=(h+1)%H;//int w=ishf();
		a[0]=h/10;a[1]=h%10;a[2]=m/10;a[3]=m%10;//做相同操作 
			for(int i=0;i<4;i++){
			if(2==a[i])a[i]=5;
			else if(5==a[i])a[i]=2;
		}
		m1=a[1]*10+a[0];h1=a[3]*10+a[2];//更新h1,m1 
	}
	printf("%02d:%02d",h,m);
 	return 0;
}

