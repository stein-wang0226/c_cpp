//Ô¼Éª·ò»·

# include <string.h>
#include<stdio.h>
int main(){
int n,num;char s[55]="\0";
scanf("%d\n",&n);
gets(s);
int lens=strlen(s);
for(int i=0;i<lens;i++){
s[i]=(s[i]-'a'+n)%26+'a';}
puts(s);
return 0;
}
