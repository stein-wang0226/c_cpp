#include<bits/stdc++.h>
//合数直接输出  ，质数减去一个奇数即可
using namespace std;

int a[105],t,n;
int isprime(int a){
	int bound=sqrt(a);
	for(int i=2;i<=bound;i++){
		if(!(a%i))return 0;	
	}
	return 1;
}
int main() {
	cin>>t;
	while(t--) {
		int sum=0;
		memset(a,0,sizeof a);
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int pos=0;
		if (!isprime(sum)){//合数  全部输出 
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("%d ",i); 
		}
		else{
				for(int i=1;i<=n;i++){
					if(a[i]%2){//找一个奇数删去 
						pos=i;break;
					}
				}
				printf("%d\n",n-1);
				for(int j=1;j<=n;j++){
					if(j!=pos)printf("%d ",j);
				} 
				
		} 
		cout<<"\n";

	}
	return 0;
}
