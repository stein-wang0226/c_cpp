#include<bits/stdc++.h>
//˼ά    ��ΪX��Ϊ unexitable   so ����Ψһȷ��grid  ������.��Ϊexitable    ����ֻ���ж���.������϶���X  ��undetermined������exitable �ز��������������
using namespace std ;
const int N =1e6+8;
int sum[N];
int biao[N];
int main() {
	int n ,m ,tem= 0 ;
	scanf("%d%d",&n,&m);
	char ve[n+10][m+10];
	for(int i= 1; i<=n; i++)scanf("%s",ve[i]+1);//һ�ζ�һ�� ,�±��1��ʼ 
	int s;
	scanf("%d",&s);
	for(int j=1 ; j<=m; j++) {
		for(int i =1 ; i<=n; i++) {
			if(i==1||j==1)continue;
			if((ve[i-1][j]=='X')&&(ve[i][j-1]=='X')) {//unexitable 
				biao[j]=1;//ĳһ�� ��ȷ�� 
				break;
			}
		}
	}
	for(int i =1; i<=m; i++) {
		if(biao[i])sum[i]=sum[i-1]+1;//ǰ׺�� 
		else sum[i]=sum[i-1];
	}
	while(s--) {
		tem=0;
		int a,b;
		scanf("%d%d",&a,&b);
		if(!(sum[b]-sum[a])cout<<"no"<<endl;//ǰ׺���ж�a~b���Ƿ�ȫ  determined 
		else cout<<"yes"<<endl;
	}
	return 0;
}







