#include<bits/stdc++.h>
//˼ά    һ������ĳ����δ��b�г��ֹ������ǰѸõ���Ϊ���������㶼��Ϊ�������ӽڵ㣬���ɵ���һ������������
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn],m,n,t;
set<int>st;
int main() {
	cin>>t;
	while(t--) {
		scanf("%d %d",&n,&m);
		st.clear();
		for(int i=1; i<=m; i++) {
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			st.insert(b[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){//�ҵ�δ��b[i]�г��ֹ��� һ����root 
			if(!st.count(i)){
				cnt=i;break;
			}	
		} 
		
		for(int i=1;i<=n;i++){
			if(i!=cnt)printf("%d %d\n",cnt,i);
		} 
	}
	return 0;
}
