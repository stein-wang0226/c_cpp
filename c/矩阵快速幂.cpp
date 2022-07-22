#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int N=105;
long long ans[N][N] ;
long long tmp[N][N];
long long a[N][N];
const long long T=1e9+7;
void mul(long long a[][N],long long b[][N],int n) {//矩阵乘法,n为大小 ，用a存结果 ，不用返回二维数组
	memset(tmp,0,sizeof tmp);//tmp暂存结果
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int m=0; m<n; m++) {
				tmp[i][j]+=(a[i][m]*b[m][j]%T)%T;
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
		a[i][j]=tmp[i][j]%T;//用a存结果
		}
	}
}
void ksm(long long a[][N], long long k) {//快速幂运算循环法更优 
    while(k != 0) {
	if(k %2) {//ji 
	    mul(ans,a,n);//奇数,将奇数个累乘，结果存于ans最后k=1 时×上所有偶数的n 
	}
	mul(a,a,n);//偶
	k >>= 1;//指数减半 
    }
}
int main() {
	cin>>n;
	scanf("%lld",&k);
	for(int i=0; i<n; i++) {//input 
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			if(i==j)ans[i][j]=1;//ans赋为单位阵 以做乘法 
		}
	}

	ksm(a,k);
	 for(int i=0; i<n; i++) {//output 
		for(int j=0; j<n; j++) {
				printf("%lld ",	ans[i][j]%T);
		}
		cout<<"\n";
	}
}
//long long ksm(long long  n,int k) {//递归快速幂 
//	if (!k)return 1 ;
//	while(k) {//最后k=0 跳出
//		if(k%2) return n*ksm(n,k-1);//k=1时返回n*1
//		else  {
//			n*=n;
//			k>>=1;
//		}
//	}
//
//}














