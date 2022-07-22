# include <stdio.h>
# include <string.h>

int main(void)
{
    char s[20]="\0";
   gets(s);
   int n=strlen(s);
// for(int i=0;i<n;i++)printf("%c\n",s[i]);puts(s);printf("%s\n",s);
//char t='\0';
//t=s[0];s[0]=s[2];s[2]=t;
//
// for(int i=0;i<n;i++)printf("%c\n",s[i]);

if(s[n-1]!='0'){

 	if(s[0]=='-'){
 	char t='\0';
		//2
 	for(int i=1;i<=n/2;i++){t=s[i];s[i]=s[n-i];s[n-i]=t;t='\0';
	 }
 	puts(s);	
 	}
 	else{
 		char t='\0';
 		for(int i=0;i<=(n-1)/2;i++){t=s[i];s[i]=s[n-1-i];s[n-1-i]=t;t='\0';}			
	 								
 	puts(s);
		}
}
else{ int N=n;for(int i=N-1;i>=0;i--)
		{if (s[i]=='0') {s[i]='\0';n--;}//       去结尾连续0 
		 else  break;

		}
		if(s[0]=='-'){
 		char t='\0';		
	 	for(int i=1;i<=n/2;i++){t=s[i];s[i]=s[n-i];s[n-i]=t;t='\0';
		 }
	 	puts(s);	
	 	}
	 	else{
	 		char t='\0';
	 		for(int i=0;i<=(n-1)/2;i++){t=s[i];s[i]=s[n-1-i];s[n-1-i]=t;t='\0';}			
		 								
	 	puts(s);
			}

		
	
	}
 return 0;
}
