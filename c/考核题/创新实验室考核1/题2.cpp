#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	char m[50],n[50];//֮ǰ ��Ұָ�뵼�� segsentation fault 
	double a,b,db[4];int c,d,l1,l2;
	int i[4];
	
	while(scanf("%s %s",m,n)!=EOF)//�������� 
	{

	a=atof(m);b=atof(n);//
	db[0]=a+b;
	db[1]=a-b;
	db[2]=a*b;
	db[3]=a/b;
	
		for(int t=0;t<4;t++)
		i[t]=(int)db[t];//��������� 
		
		for(int j=0;j<4;j++)
		{
			if (fabs(db[j]-i[j])<1e-6||fabs(db[j]-i[j]+1)<1e-6||fabs(db[j]-i[j]-1)<1e-6)//�ж��Ƿ�Ϊ���� ��ע�⸺�� 
			{
			if(fabs(db[j]-i[j]+1)<1e-6)printf("%d",i[j]-1);
			else if(fabs(db[j]-i[j]-1)<1e-6)printf("%d",i[j]+1);
			else printf("%d",i[j]);
			}
			
			else printf("%.3lf",db[j]);
			
			if(j<3)printf(",");
		}		
		
	
 	}	
	return 0;
	
}
