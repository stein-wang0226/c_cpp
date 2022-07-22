#include <bits/stdc++.h>
using namespace std;
double a[55],k;
int t,n,cnt;

int main() {

	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {//input
			cin>>a[i];
		}
		cnt=0;
		for(int j=0; j<n-1; j++) {
			k=0;
			k=max(a[j],a[j+1])/min(a[j],a[j+1]);
			while(k>2) {
				k/=2;
				cnt++;
			}
		}

		cout<<cnt<<endl;
	}
	return 0;
}

























































































































































































































