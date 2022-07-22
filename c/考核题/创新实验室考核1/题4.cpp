#include<stdio.h>
int main()
{
int n,x,y,cnt=0,a[11][11];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)a[i][j]=0;//memset(a,0,sizeof(a))
	}
if (n<3||n>10) return 0;


else{

cnt=a[x=0][y=0]=1;//赋初值1，1 
	
		while(cnt<n*n)//以右下左上的次序赋值， 
		{
			while(y+1<n &&!a[x][y+1]) a[x][++y]=++cnt; //right ,注意是++y 
			while(x+1<n&&!a[x+1][y]) a[++x][y]=++cnt; //down 
			while(y-1>=0&&!a[x][y-1]) a[x][--y]=++cnt; //left
			while(x-1>=0&&!a[x-1][y]) a[--x][y]=++cnt; //up
			
		}
	for(x=0;x<n;x++)
	{
		for(y=0;y<n;y++)printf("%-4d",a[x][y]);
		printf("\n");
	}	
		
		
	}
	
	
	
	
	
	return 0;
	
}
