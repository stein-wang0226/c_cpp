    #include<stdio.h>
    #include<string.h>
  
   
    int main(){
 //未知个数的输入
 int n,a[20]={0},b[20][20],max=0,MAX=0,time,sum=0;//b储存没次取牌情况 
 scanf("%d",&a[0]);//input 
 	for(n=1;getchar()!='\n';n++)scanf("%d",&a[n]);//回车结束输入，n位个数 
	int cnt,maxi,end=1;
while(end)
{
	int i;max=0;maxi=-1;
	for(i=0;i<n;i++)
	{
	if(a[i]==0)continue;
		cnt=1;
		b[i][0]=i;//每次遍历从第i开始拿的情况，贪心取最大 b i，j表示从i开始取的一轮 取的第j张 的位置 
		
		if((i==n-1)&&a[i]){b[i][0]=i;}//cnt=1， 只剩最后一张的情况 
		else{
				for(int j=i+1;j<n;j++)//i=n-1 is not included
				{	 
				
					if( a[j]<a[b[i][cnt-1]]&&a[j])//小于上一次 
					{
					b[i][cnt]=j;cnt++;
					}
					
					
				}
	
	
		   }
	if(cnt>max){max=cnt; maxi=i;}//寻找从maxi开始最大的maxi 
			
	}
	for(int h=0;h<max;h++)a[b[maxi][h]]=0;//找到一轮最大值，将该情况取的牌 赋为0 ,表示已被取走 
	time++;sum+=max;
	if(MAX<max)MAX=max;
end=0;
for(int m=0;m<n;m++) {
end+=a[m];	 } 
}
      
      
      
      
      printf("%d\n%d",MAX,time);
      return 0;
    }
    
    
    
    
    
    

