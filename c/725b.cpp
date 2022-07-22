#include<bits/stdc++.h>

const int N=1e5+5;
int t,n,m;
int  a[N];
int b[5];
int main() {
	scanf("%d",&t);
	while(t--) {
		int ans=0;

		scanf("%d %d",&n,&m);
		for(int i=0; i<m; i++) {
			scanf("%d",&a[i]);
		}
		for(int j=0; j<m; j++) { //×öÍ°
			b[a[j]]++;
		}
		if(b[3]>=b[1]) {
			ans=b[4]+b[3]+(b[2]+1)/2;
		} else if(b[1]-b[3]<=b[2]/2)	ans=b[4]+b[3]+b[2]/2+b[1];
		else ans=b[4]+b[1];
		

		printf("%d\n",ans);
	}

	return 0;
}
