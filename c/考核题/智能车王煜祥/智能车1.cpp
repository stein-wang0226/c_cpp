# include <string.h>
#include<stdio.h>
int main(){
int a[100][100],b[100],m,n,max=-1,min=110,sum=0,mini=0,maxi=0;
scanf("%d %d",&n,&m);//����
for(int i=0;i<n;i++)b[i]=0; 
for(int i=0;i<n;i++)//���� 
{
	for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			
	    }
	
}
		
	for(int i=0;i<n;i++)//���� 
   {
	for(int j=0;j<m;j++)
		{
		   if(a[i][j]==0  )
		   {
		  		b[i]++;sum++;
			}	
		}
			if(b[i]>max)
			{
				max=b[i];maxi=i+1	;
			}
			if(b[i]<min)
			{
				min=b[i];	mini=i+1;
			}
    }


printf("%d %d %d ",sum,max,min);                                    //���

 






















	return 0;
	}
