    #include<stdio.h>
    #include<string.h>
  
   
    int main(){
 //δ֪����������
 int n,a[20]={0},b[20][20],max=0,MAX=0,time,sum=0;//b����û��ȡ����� 
 scanf("%d",&a[0]);//input 
 	for(n=1;getchar()!='\n';n++)scanf("%d",&a[n]);//�س��������룬nλ���� 
	int cnt,maxi,end=1;
while(end)
{
	int i;max=0;maxi=-1;
	for(i=0;i<n;i++)
	{
	if(a[i]==0)continue;
		cnt=1;
		b[i][0]=i;//ÿ�α����ӵ�i��ʼ�õ������̰��ȡ��� b i��j��ʾ��i��ʼȡ��һ�� ȡ�ĵ�j�� ��λ�� 
		
		if((i==n-1)&&a[i]){b[i][0]=i;}//cnt=1�� ֻʣ���һ�ŵ���� 
		else{
				for(int j=i+1;j<n;j++)//i=n-1 is not included
				{	 
				
					if( a[j]<a[b[i][cnt-1]]&&a[j])//С����һ�� 
					{
					b[i][cnt]=j;cnt++;
					}
					
					
				}
	
	
		   }
	if(cnt>max){max=cnt; maxi=i;}//Ѱ�Ҵ�maxi��ʼ����maxi 
			
	}
	for(int h=0;h<max;h++)a[b[maxi][h]]=0;//�ҵ�һ�����ֵ���������ȡ���� ��Ϊ0 ,��ʾ�ѱ�ȡ�� 
	time++;sum+=max;
	if(MAX<max)MAX=max;
end=0;
for(int m=0;m<n;m++) {
end+=a[m];	 } 
}
      
      
      
      
      printf("%d\n%d",MAX,time);
      return 0;
    }
    
    
    
    
    
    

