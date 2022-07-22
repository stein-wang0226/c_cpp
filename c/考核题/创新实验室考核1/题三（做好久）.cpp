#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//判断+排序+字符串处理 
//困难在于长度不确定 

	int max(int a,int b ){
		int c;
		c=a>b?a:b;
		return c;
		
	}
	int min(int a,int b ){
		int c;
		c=a<b?a:b;
		return c;
		
	}	
	
int main(){
	int n;
	char a[20][100];//若用指针数组需初始化 
	int len[20];
	scanf("%d",&n);
if(n<1||n>20) exit(0);
//start rank
else{
		for(int i=0;i<n;i++) scanf("%s",a[i]);//读入n个字符串 
		for(int i=0;i<n;i++) len[i]=strlen(a[i]);
		//选择paixu
		int k=0;
		int sy[20];//索引,字符串交换不方便 
		int temp=-1;//meijie
		for(int i=0;i<n;i++)sy[i]=i;
		 for(int i=0;i<n;i++)
		 {
		 k=i;
		 	for(int j=i+1;j<n;j++)
		 	{
			 	for(int t=0;t<max(len[j],len[i]);t++)
			 	{	
			 		int p=t%min(len[j],len[i]);//新下标，短字符串循环比较 
			 		if(len[i]>len[j])//
					{ 
						if (a[j][p]>a[i][t])
						
					 	{ k=j;
					 		break;
					 	}
						
						if (a[j][p]==a[i][t]) 
						{
						 continue;
						}
			 				
					    else break; 
					} 
					else//
					{
						if (a[j][t]>a[k][p])
						 	{ k=j;
						 		break;
						 	}
							
							if (a[j][t]==a[i][p]) 
							{
							 continue;
							}
							
				 				
						    else break; 		
						
					 } 
					 					 										 					 	
					 		 			
			 	}
		 		
		 		
		 	int temp2;
		 	temp2=sy[i];sy[i]=sy[k];sy[k]=temp2;
			}
		 		
		 	
		 	
		 }//end rank
		//output
			
     	for(int i=0;i<n;i++)	
		{
			
			printf("%s",a[sy[i]]);
			
			}	
			
		
		

	
	

	
	} 
	return 0;
	
}
