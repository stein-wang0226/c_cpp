#include <bits/stdc++.h>//��������������� 
using namespace std;
struct w_v {
	int w,v,index;//index����ԭʼ��� �������¼�����
} a[1005];
int dp[1005];
bool cmp(w_v a,w_v b) {
	return a.w<b.w;//����������
}
int main() {
	int k=1;//�������
	while(~scanf("%d %d",&a[k].w,&a[k].v)) { //input
		a[k].index=k;
		k++;
	}
	k--;
	sort(a+1,a+k+1,cmp);
	//���ٶ���� ������
	int maxdp=1;
	dp[1]=1;
	for(int i=2; i<=k; i++) { //dp
		int maxlen=0;//��¼�ֵ
		for(int j=1; j<i; j++) {
			if(a[j].w==a[i].w)continue;//֮ǰ���Զ�����
			if(a[j].v>a[i].v&&dp[j]>maxlen)maxlen=dp[j];
		}
		dp[i]=maxlen+1;//��i��β����������г���
		if(dp[i]>maxdp)maxdp=dp[i];//
	}
	printf("%d\n",maxdp);
//	for(int i=1;i<=k;i++){
//		cout<<dp[i]<<endl;
//	}
	//�ƴ�
	int curlen=maxdp;//��ǰ����
	int cur_amin=0;//��ǰĩβֵ
	int ans[1005];
	for(int i = k; i > 0,curlen>0; i--) { //�Ӻ�����ǰ����
		if(curlen == dp[i]&&a[i].v>cur_amin) {
			ans[curlen] = a[i].index;
			curlen--;
			cur_amin = a[i].v;
		}
	}
	for(int m=1; m<=maxdp; m++) {
		cout<<ans[m]<<endl;
	}



	return 0;
}
