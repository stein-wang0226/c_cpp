#include <bits/stdc++.h>
using namespace std;
int a[30005],c[3];
int t,n,cnt,Max,maxc,average;
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {//input
			cin>>a[i];
		}
		memset(c,0,sizeof c);
		for(int i=0; i<n; i++) {
			c[a[i]%3]++;
		}
		average=n/3;
		Max=c[0];
		for(int j=0; j<3; j++) { //find the most
			if(c[j]>Max) {
				Max=c[j];
				maxc=j;
			}
		}
		cnt=0;
		for(int i=0; i<=3; i++) {
			if(c[(maxc+i)%3]>average) { //从maxc开始向后移
				c[(maxc+i+1)%3]+=(c[(maxc+i)%3]-average);
				cnt+=(c[(maxc+i)%3]-average);//记录移动个数
				c[(maxc+i)%3]=average;
			}
		}

		cout<<cnt<<endl;
	}
	return 0;
}

























































































































































































































