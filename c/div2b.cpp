#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int t;
ull n,k,cur;
int main() {
	cin>>t;
	while(t--) {
		int flag=0;
		scanf("%llu %llu",&n,&k);
		cur=1;
		ull cnt=0;
		while(cur<k) {
			cnt++;
			cur*=2;
			if(cur>n) {
				printf("%llu\n",cnt);
				flag=1;
				break;
			}
		}
		if(flag)continue;
		if((n-cur)%k) {
			cnt+=((n-cur)/k+1);
		} else {
			cnt+=(n-cur)/k;
		}
		printf("%llu\n",cnt);

	}
	return 0;
}


