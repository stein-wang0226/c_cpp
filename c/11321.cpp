//����������� �������Ӵ��� ȫ���� LIS����ջ nlogn ����ΪԪ����ͬ��˳��ת��Ϊ��������������
//p1439   ˼·����a1 ��Ϊ��׼  ��a1[1]~a1[n]->1 ,2~n;a[i] i��һһӳ�� ,��a2Ҳ��Ӧ�仯�����ʱa2(��ɢ��)��¼  value[a[i]]=i;
#include <bits/stdc++.h>
using namespace std;
int n,k;
const int N =1e5+5;
int a1[N], a2[N],value[N];
int main() {
	cin>>n;
	for(int  i=1; i<=n; i++) {
		cin>>a1[i];
		value[a1[i]]=i;
	}
	for(int  i=1; i<=n; i++) {
		int x;
		cin>>x;
		a2[i]=value[x];//ӳ����a2Ȩֵ
	}
//��a[2] lis
	int len[N],tot=1;
	len[1]=a2[1];
	for(int i=2; i<=n; i++) {
		if(a2[i]>len[tot]) {
			len[++tot]=a2[i];
		}
     else{
     	k=upper_bound(len,len+tot,a2[i])-len;//��һ������a2[i]���±� ���滻����֤ĩβ������С�� 
     	len[k]=a2[i]; 
	 }
	}
	cout<<tot;
	return 0;
}
