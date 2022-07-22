


#include<stdio.h>
#include<string.h>
int main()
{
	char a[81];
	char b[81];
	gets(a);
	int t=strlen(a);
	int i,j,m,n=0;
	for(i=1;i<=t;i++)
	{
		if(t%i==0)
		{
			int x=t/i;
			for(m=1;m<=x;m++)
			{
				for(j=0;j<i;j++)
		        {
		            	b[n++]=a[j];
				}
			}
				
		}
		if(strcmp(b,a)==0)
		{
			printf("%d",i);
			break;
		}
		else
		{
			n=0;
		}
	}
	
}

