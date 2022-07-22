#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long k;

unsigned long long f(int n,long long k) {
	if(1==n&&k==1)return 0;
	if(1==n&&k==2)return 1;
	if(n<64) {
		unsigned long long ans=(unsigned long long)1<<n;
		if(k<=ans/2)return f(n-1,k);
		else return f(n-1,ans-k+1)+ans/2;
	}

}
int main() {
	unsigned long long ans0=0;
	string str="";
	cin>>n>>k;
	ans0=f(n,k+1);
	int cnt=n;
	if(n==64) { //最后一个测试点，返回值超ull,其实可用下面通解，也可用返回字符串解决 
		for (int i = n-1; i >= 0; i --) {
			unsigned long long tmp = k >> i;
			putchar( tmp%4==1 || tmp%4==2 ? '1' : '0' );
		}
		return 0;
	}
	while(ans0>0) {
		if (ans0&1)str='1'+str;
		else str='0'+str;
		ans0>>=1;
		cnt--;
	}
	while(cnt--)str='0'+str;//
	cout<<str;
	return 0;
}
