#include<bits/stdc++.h>
#define  ll long long
using namespace std;
ll t,n,a[200005],b[200005],ans;
set<ll > st;
int main() {
	ios::sync_with_stdio(false);//此时不能混用scanf 
	cin >>t;
	while(t--) {
		ans=1e15;
		cin>>n;
		for(ll i=1; i<=n; i++)cin >>a[i];
		a[n+1]=0;
		sort(a+1,a+n+1);
		ll t=1;
		int cnt=0;
		for(ll i=1; i<=n+1; i++) {
			if(a[i]!=a[t]) {
				b[++cnt]=i-t;//共cnt个桶 
				st.insert(i-t);
				t=i;
			}
		}
		for(auto i:st) {//yi set中第i个数为 （去重后）biaozhun
			ll sum=0;
			for(int j=1; j<=cnt; j++) { 
				if(b[j]<b[i])sum+=b[j];
				else if (b[j]>b[i]) sum+=b[j]-b[i];
			}
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
