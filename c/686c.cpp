#include<bits/stdc++.h>
using namespace std;
//分析每个数排列方式和出现次数
const int N =2e5+5;
int t,n,a[N],b[N],vis[N];
int main() {
	cin>>t;
	while(t--) {
		memset(vis,0,sizeof vis);
		memset(b,0,sizeof b);
		scanf("%d",&n);
		for(int i=0; i<n; i++) { //input
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++) { //b 桶 储存有效出现次数（能分割 数串）
			b[a[i]]++;
			vis[i]=1;//防止只有头尾出现却被判断为未出现过
			if(0==i||(n-1)==i||(a[i]==a[i-1]))b[a[i]]--;//头 尾 和连续 ,之前为考虑第四种情况：尾连续 
		}
			if(a[n-1]==a[n-2])b[a[n-1]]--;//特判尾连续 
		int flag=1;
		for(int i=1; i<n; i++) { //特判 全相等
			if(a[i]!=a[i-1])flag=0;
		}
		if(flag) {
			cout<<"0"<<"\n";
		continue;
		}
		int Min=N+1;
		for(int i=0; i<n; i++) { //b 储存有效出现次数（能分割）
			if (vis[i])Min=min(Min,b[a[i]]);//
		}
		cout<<Min+1<<"\n";
	}
	return 0;
}
