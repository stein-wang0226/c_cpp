#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		long long i;
		int n;//������Ϊn
		scanf("%lld",&i);
	                       // ����Ѱ�һᳬʱ
			int cnt=0;
			long long i1=i ;//�Է��ı�i1 
			while (i1) { //����λ��cnt
				i1/=10;
				cnt++;
			}
			n=(cnt-1)*9;//�������λ�����������,
			long long k=0;
			while(cnt--) { //�����λ��Ӧ�� cnt��1���� 
				k=k*10+1;
			}
			n+=i/k;

		
		printf("%d\n",n);
	}
	return 0;



}
