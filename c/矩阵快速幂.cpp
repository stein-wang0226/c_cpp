#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int N=105;
long long ans[N][N] ;
long long tmp[N][N];
long long a[N][N];
const long long T=1e9+7;
void mul(long long a[][N],long long b[][N],int n) {//����˷�,nΪ��С ����a���� �����÷��ض�ά����
	memset(tmp,0,sizeof tmp);//tmp�ݴ���
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int m=0; m<n; m++) {
				tmp[i][j]+=(a[i][m]*b[m][j]%T)%T;
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
		a[i][j]=tmp[i][j]%T;//��a����
		}
	}
}
void ksm(long long a[][N], long long k) {//����������ѭ�������� 
    while(k != 0) {
	if(k %2) {//ji 
	    mul(ans,a,n);//����,���������۳ˣ��������ans���k=1 ʱ��������ż����n 
	}
	mul(a,a,n);//ż
	k >>= 1;//ָ������ 
    }
}
int main() {
	cin>>n;
	scanf("%lld",&k);
	for(int i=0; i<n; i++) {//input 
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			if(i==j)ans[i][j]=1;//ans��Ϊ��λ�� �����˷� 
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
//long long ksm(long long  n,int k) {//�ݹ������ 
//	if (!k)return 1 ;
//	while(k) {//���k=0 ����
//		if(k%2) return n*ksm(n,k-1);//k=1ʱ����n*1
//		else  {
//			n*=n;
//			k>>=1;
//		}
//	}
//
//}














