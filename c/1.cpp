#include<stdio.h>
#include<string.h>


int main() {
	int t;

	int isend[30]= {0}; //是否学完
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		char s[55];
		getchar();//过滤回车
		gets(s);
		int distract=0;
		int isend[30]= {0}; 
		for(int i=0; i<n; i++) {
			if(s[i]!=s[i-1]||i==0) {
				if(isend[s[i]-'A'+1]==1) {//判断是否分心
					distract=1;
					break;
				} else isend[s[i]-'A'+1]=1; //标志已学完。
			}
		}
		if(distract)printf("NO\n");
		else printf("YES\n");


	}

	return 0;



}
