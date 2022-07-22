#include <bits/stdc++.h>
using namespace std;
int t,n,x1,y1,x2,y2;
char  a[401][401];
int main() {

	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {//input
			for(int j=1; j<=n; j++) {
				cin>>a[i][j];
			}
		}
		int cnt=1;
		for(int i=1; i<=n; i++) {//input
			for(int j=1; j<=n; j++) {
				if(a[i][j]=='*'&&cnt) {
					x1=i;
					y1=j;
					cnt--;
				} else if(a[i][j]=='*') {
					x2=i;
					y2=j;
					break;
				}
			}
		}
		if(x1==x2) {
			for(int i=1; i<=j; i++) {
				a[j][y1]='*';
				a[j][y2]='*';
				if(j!=x1) {
					for(int i=1; i<=n; i++) {//output
						for(int j=1; j<=n; j++) {
							cout<<a[i][j];
						}
						cout<<endl;
					}

				}
			}
		} else if(y1==y2) {
			for(int i=1; i<=j; i++) {
				a[x1][j]='*';
				a[x2][j]='*';
				if(j!=y1) {
					for(int i=1; i<=n; i++) {//output
						for(int j=1; j<=n; j++) {
							cout<<a[i][j];
						}
						cout<<endl;
					}

				}
			}
		} else {
			a[x1][y2]='*';
			a[x2][y1]='*';
			for(int i=1; i<=n; i++) {//output
				for(int j=1; j<=n; j++) {
					cout<<a[i][j];
				}
				cout<<endl;
			}

		}
	}
	return 0;
}

























































































































































































































