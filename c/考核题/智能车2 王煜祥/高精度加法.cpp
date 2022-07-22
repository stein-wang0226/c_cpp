#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	char s1[201],s2[201];
	gets(s1);
	gets(s2);
	int a[201]= {0},b[201]= {0},c[202]= {0},len1,len2;
	len1=strlen(s1);
	len2=strlen(s2);
	a[0]=len1;
	b[0]=len2;//len为长度 用啊a[0 ]b[0]储存
	for(int i=1; i<=len1; i++) {
		a[i]=s1[len1-i]-'0';
	}
	for(int i=1; i<=len2; i++) {
		b[i]=s2[len2-i]-'0';
	}
	int len=(a[0]>b[0]?a[0]:b[0]);   //取两个字符串最大的长度(=数字最大长度+1)
	c[0]=len;
	for(int i=1; i<=len; i++) { //按位加并处理进位
		c[i]=c[i]+a[i]+b[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	int t=201;
	  while(c[t]==0&&t>0)t--;//最高位
	for(int i=t; i>0; i--) {
		printf("%d",c[i]);
	}











	return 0;
}
