#include<bits/stdc++.h>
using namespace std;
int n,a[500010];
map<long long,bool>mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	mp[0]=true;
	long long s=0;
	int ans=0;
	for(int i=1;i<=n;++i){
		s+=a[i];
		if(mp[s]){
			ans++;
			mp.clear();
			mp[0]=true;
			s=a[i];
		}
		mp[s]=true;
	}
	cout<<ans<<endl;
	return 0;
}
