#include<bits/stdc++.h>
using namespace std;
//����ÿ�������з�ʽ�ͳ��ִ���
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
		for(int i=0; i<n; i++) { //b Ͱ ������Ч���ִ������ָܷ� ������
			b[a[i]]++;
			vis[i]=1;//��ֹֻ��ͷβ����ȴ���ж�Ϊδ���ֹ�
			if(0==i||(n-1)==i||(a[i]==a[i-1]))b[a[i]]--;//ͷ β ������ ,֮ǰΪ���ǵ����������β���� 
		}
			if(a[n-1]==a[n-2])b[a[n-1]]--;//����β���� 
		int flag=1;
		for(int i=1; i<n; i++) { //���� ȫ���
			if(a[i]!=a[i-1])flag=0;
		}
		if(flag) {
			cout<<"0"<<"\n";
		continue;
		}
		int Min=N+1;
		for(int i=0; i<n; i++) { //b ������Ч���ִ������ָܷ
			if (vis[i])Min=min(Min,b[a[i]]);//
		}
		cout<<Min+1<<"\n";
	}
	return 0;
}
