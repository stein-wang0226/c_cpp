#include<bits/stdc++.h>
using namespace std;

int a[105],dep[105]={-1};
int t,n;

void solve(int l,int r,int d) {//ตÝน้ 
	int Max=a[l],maxi=l;
	if(l>r)return;
	for(int i=l; i<=r; i++) {
		if(a[i]>Max) {
			Max=a[i];
			maxi=i;
		}
	}
	dep[Max]=d;
	solve(l,maxi-1,d+1);//left 
	solve(maxi+1,r,d+1);//right


}

int main() {

	cin >> t;
	while(t --) {
		cin>>n;
		for(int i=0; i<n; i++) { //input
			cin>>a[i];
		}

		solve(0,n-1,0);
		for(int i=0; i<n; i++) { //output
			cout<<dep[a[i]]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
