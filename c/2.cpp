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
		int pos,len;
		for(int i=0; i<n; i++) {
			for(int l=0; l<=n-i; l++) {
				int cnt=0;
				memset(s1,0,sizeof(s1));
				for(int j=0; j<n; j++) { //处理 生成s1
					if(j<i||j>i+l-1) {
						s1[cnt]=s[j];
						cnt++;
					}
				}
				if(s1[0]=='2'&&s1[1]=='0'&&s1[2]=='2'&&s1[3]=='0')	{
				is2020=1;
				i=n;//跳出外层循环
				break;
			}
		}
	}
if(is2020==1)printf("YES\n");
else printf("NO\n");

}


return 0;



}
