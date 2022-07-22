#include<bits/stdc++.h>
const int N =2e5+5;
int t,n;
int a[N];
int vis[N];
using namespace std;
int main() {
	int t,n;
	cin>>t;
	set<int>s;//用于判断重复
	set<int>m;
	while(t--) {
		memset(vis,0,sizeof vis);//0为未重复
		s.clear();
		m.clear();

		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++) {
			if(!s.count(a[i])) {
				s.insert(a[i]);
			} else {//记录重复数
				m.insert(a[i]);
			}
		}
		int Min=N+5;
		for(int i=0; i<n; i++) {
			if(!m.count(a[i]))Min=min(Min,a[i]);
			}
		int i;
		for( i=0; i<n; i++) {
			if(a[i]==Min&&!m.count(a[i])) {
				int ans=i+1;
				cout<<ans<<"\n";
				break;
			}
		}
		if(i==n)cout<<"-1"<<"\n";

	}
	return 0;
}
