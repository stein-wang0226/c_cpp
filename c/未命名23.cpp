#include <bits/stdc++.h>//dfs 
using namespace std;
int n,a,b,k[201],minstep,step=0;
int vis[201];//����Ƿ��Ѿ�����
void dfs(int x,int y);
int main() {
	cin>>n>>a>>b;
	minstep=n+1;//��֤���ı�
	for(int i=1; i<=n; i++)cin>>k[i]; //input
	memset(vis,0,sizeof(vis));
	dfs(a,0);
	if(vis[b])printf("%d",minstep);
	else cout<<"-1";
	return 0;
}
void dfs(int a,int step) {
	if(a<1||a>n)return; //unvalid
	if(a==b||step>=n||vis[a]||step>minstep) { //�������� ���н����Ϊnʱ�����н�,�Ѿ��������ظ�����֦ 
		if(step<minstep&&a==b) {//���Ž����¼ 
			minstep=step;
			vis[b]=1;//��Ǵ����н� 
		}
		return;
	}
	vis[a]=1;
	step++;
	dfs(a+k[a],step);
	dfs(a-k[a],step);
	vis[a]=0;//���� 
}













