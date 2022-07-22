#include <bits/stdc++.h>
using namespace std;
const int N=15;
int a[N][N],vis[N][N];
int n,R;

int is_valid(int x,int y) { 
	for(int i=0; i<n; i++) { //查同一列
		if(vis[i][y]==1)return 0;
	}
	int xi,yi;//不能在for内int2次
	for( xi=x, yi=y; xi>=0&&yi>=0; xi--,yi--) { //查左对角线，因为从上往下填，所以不用考虑下方
		if(vis[xi][yi]==1)return 0;
	}
	for( xi=x, yi=y; xi>=0&&yi<n; xi--,yi++) { //查右对角线
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
int num=3;//计数前3个
void dfs(int row0) { //一行一行填

	if(row0==n) { //跳出条件
		if(num) {
			num--;	   //输出该解
			print();
		}
		cnt++;
		return;
	}
	for(int i=0; i<n; i++) { //遍历每列i
		if (is_valid(row0,i)) {
			vis[row0][i]=1;//填上

			dfs(row0+1);//递归遍历
			vis[row0][i]=0;//回溯(找到一种以后)

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
