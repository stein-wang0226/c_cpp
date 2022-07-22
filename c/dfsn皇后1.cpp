#include <bits/stdc++.h>
using namespace std;
const int N=15;
int a[N][N],vis[N][N];
int n,R;

int is_valid(int x,int y) { 
	for(int i=0; i<n; i++) { //��ͬһ��
		if(vis[i][y]==1)return 0;
	}
	int xi,yi;//������for��int2��
	for( xi=x, yi=y; xi>=0&&yi>=0; xi--,yi--) { //����Խ��ߣ���Ϊ������������Բ��ÿ����·�
		if(vis[xi][yi]==1)return 0;
	}
	for( xi=x, yi=y; xi>=0&&yi<n; xi--,yi++) { //���ҶԽ���
		if(vis[xi][yi]==1)return 0;
	}
	return 1;
}
void print() { //output
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(vis[i][j]==1) {
				cout<<j+1<<" ";
			}
		}
	}
	cout<<"\n";
}

int cnt=0;
int num=3;//����ǰ3��
void dfs(int row0) { //һ��һ����

	if(row0==n) { //��������
		if(num) {
			num--;	   //����ý�
			print();
		}
		cnt++;
		return;
	}
	for(int i=0; i<n; i++) { //����ÿ��i
		if (is_valid(row0,i)) {
			vis[row0][i]=1;//����

			dfs(row0+1);//�ݹ����
			vis[row0][i]=0;//����(�ҵ�һ���Ժ�)

		}
	}
}


int main() {
	memset(vis,0,sizeof vis);
	cin>>n;
	dfs(0);
	cout<<cnt;
	return 0;
}
