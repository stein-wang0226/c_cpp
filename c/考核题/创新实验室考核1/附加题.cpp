    #include<stdio.h>
    #include<string.h>
  
    int n;
	int maxlenf();
	int len[20];	
	int temp,maxi;
	//����ÿһ�����е���Ϊ���Ҷ�ʱ��������г���
	//������ÿ���β��󳤶� 
	
 //δ֪����������
 int a[20]={0};
 
 
 int main(){
 scanf("%d",&a[0]);//input 
 	for(n=1;getchar()!='\n';n++)scanf("%d",&a[n]);//�س��������룬nλ���� 

//	printf("%d",n);
	
	
	
	int maxtemp;			
	int time=0;	
int end=1;//to stop loop	
while(end)
{
	maxlenf();

	if (temp>maxtemp)maxtemp=temp;
	
	
	int tempi=temp;int b[20];//Ϊʵ������ȡ�ƣ�ͨ�����ƴ���ÿ�����±꣬��0���� 
	b[0]=maxi;
	for(int k=1;k<temp;k++)
	{
		for(int j=0;j<maxi;j++)
		{
			if(len[j]==tempi-1&&a[j]&&a[j]>a[b[k-1]])//֮ǰ©�˵������������³��� 
			{
				b[k]=j;tempi--;
			}
		}
	}


	for(int i=0;i<temp;i++)a[b[i]]=0;


end=0;//��ʵ��ȫΪ0ʱ�������� 
for(int m=0;m<n;m++) {
end+=a[m];	 } 



time++;
    


}

printf("%d\n",maxtemp);
printf("%d",time);



  return 0;
}




int maxlenf()//���ֵ���� 
		{
		
			
	
			 for(int i=0;i<n;i++)
			 {
			    len[i]=1;  /*��ʼÿһ�����е���Ϊ���Ҷ�ʱ��������г���Ϊ1*/
			 }
			len[0]=1;
			 	 for(int i=1;i<n;i++)//��ÿ�� ��β��󳤶� 
			       {if(a[i]==0)continue;
			         temp=1;
				    	for(int j=0;j<i;j++)
						{ /*����ǰ���ÿһ�����бȽ�*/
				    	  if(a[i]<a[j]&&a[j])
							  { /*������ݱ�ǰ���ĳһ����ֵС*/
					        	if(len[j]+1>temp)
								{ /*��a[j]������a[i]��β�󳤶���������aj��β��������г���*/
					          	temp=len[j]+1;
						        } 
						      }
					    }
			    		len[i]=temp;
					}
			  temp=0;
			  for(int i=1;i<n;i++)//�Ƚ�ÿ������ֵ 
			  {
				    if(len[i]>temp&&a[i])
					{
				      temp=len[i];
				      maxi=i;
				    }
			  }	
		
		return temp;
        }   

//����������⣬˼·����̬�滮

//   �������Ѷ������ǰn��������һ�����ڶ���   ��n��  �ֱ�����Ե�һ�����ڶ����� ��n����β��������ݼ����� �����ȼ�Ϊlen[n] 
//    ��ô�������������n+1����ʱ����ֻ��������ǰ�Ƚϣ��ҵ�ÿ���ȵ�n+1λС���� ��������X��X>N��λ  ��
//   ���������Ѿ��õ�����Ե�XλΪ��β����������������еĳ��ȣ�����Y�� 
//    ����  ���ǵ���n+1λλ��β����������������м�ΪY+1 
//  ����������ǰ�Ա� ǰn��������n+1��β�������г���  ������ֵ��Ϊlen[n+1] 
//�������Ǵӵ�һλ����ֱ����������   �Ϳ��Եó���ÿһλΪ��β����������������еĳ��ȡ� ����len�����ֵ���� 





















    
    
    
    
    
    

