#include<bits/stdc++.h>
//思维    一定存在某个点未在b中出现过，于是把该点作为根，其他点都作为这个点的子节点，构成的树一定满足条件。
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn],m,n,t;
set<int>st;
int main() {
	cin>>t;
	while(t--) {
		scanf("%d %d",&n,&m);
		st.clear();
		for(int i=1; i<=m; i++) {
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			st.insert(b[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){//找到未在b[i]中出现过的 一个作root 
			if(!st.count(i)){
				cnt=i;break;
			}	
		} 
		
		for(int i=1;i<=n;i++){
			if(i!=cnt)printf("%d %d\n",cnt,i);
		} 
	}
	return 0;
}
