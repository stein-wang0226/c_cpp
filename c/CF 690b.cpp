#include<stdio.h>
#include<string.h>


int main() {
	int n,t;
	scanf("%d",&t);
	while(t--) {
		char s[201],s1[201];
		int is2020 =0;
	scanf("%d",&n);
		scanf("%s",s);
		if(s[0]=='2'&&s[1]=='0'&&s[2]=='2'&&s[3]=='0'&&n==4)is2020 =1;//case 3 2020
		int pos,len;
		for(int i=0; i<n; i++) {//i 为删除起点 
			len=n-4; //l为删除长度 
				int cnt=0;
				memset(s1,0,sizeof(s1));
				for(int j=0; j<n; j++) { //处理 生成s1
					if(j<i||j>i+len-1) {//*判断 
						s1[cnt]=s[j];
						cnt++;
					}
				}
				if(s1[0]=='2'&&s1[1]=='0'&&s1[2]=='2'&&s1[3]=='0'&&cnt==4)	{
				is2020=1;
				i=n;//跳出外层循环
				break;
			}
		}
	

if(is2020==1)printf("YES\n");
else printf("NO\n");

}


return 0;



}
