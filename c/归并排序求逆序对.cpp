#include<bits/stdc++.h>
using namespace std;
//������� �鲢����������� �Ĺ���==
const int N=5e5+5;
long long a[N],ans[N],cnt=0,n;//ans��¼����Ե�������
void msort(long long *a,int l,int r) {
	if(l>=r) return ;
	int mid=(l+r)/2;
	msort(a,l,mid);//�ݹ������
	msort(a,mid+1,r);//
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r) {
		if(a[i]>a[j]) {
			ans[k++]=a[j++];
			cnt+=mid-i+1;}//��Ϊa[i]-a[mid]������˳������ ����a[j]֮ǰ��mid-i+1�������
		else {
			ans[k++]=a[i++];
		}
	}
	while(i<=mid)
		ans[k++]=a[i++];
	while(j<=r)
		ans[k++]=a[j++];
	for(int i=l; i<=r; i++)
		a[i]=ans[i];
}
int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%lld",&a[i]);
	msort(a,0,n-1);//��1��n��a��������
	cout<<cnt<<"\n";
	return 0;
}
