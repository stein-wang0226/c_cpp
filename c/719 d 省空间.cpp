#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>

int main() {
	int t;
	scanf("%d",&t); 
	while(t--) {
		long long n;
		long long a[200005];
		scanf("%lld", &n);//ÊäÈën¸öÊı

		for (int i = 1; i <= n; i++) {

			scanf("%lld", &a[i]);
		}
		long long cnt=0;
		for (int i = 1; i < n; i++) {
			for (int j=i+1; j<=n; j++) {
				if(a[i]-a[j]==i-j)cnt++;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
