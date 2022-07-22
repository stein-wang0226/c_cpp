#include <stdio.h>//ตÝน้ 
int  m,n,x,y;
int d[2][8]={{1,1,2,2,-1,-1,-2,-2},{2,-2,1,-1,2,-2,1,-1}};

int isin(int x,int y){
	if (x>0&&y>0&&(x<=n&&(y<=m)) )return 1;
	else return 0;
}

int minstep(int a,int b) {
	int min=1e9;
	for(int i=0;i<8;i++){
		if(a-x==d[0][i]&&b-y==d[1][i]) return 1;//one step
	}
	for(int i=0;i<8;i++){
		if(minstep(a+d[0][i],b+d[1][i])<min&&isin(a+d[0][i],b+d[1][i]))min=minstep(a-d[0][i],b-d[1][i])+1;
	}
	return min;
}

int main() {
	scanf("%d %d %d %d",&n,&m,&x,&y);

 for(int i=0;i<n;i++){
 	for(int j=0;j<m;j++){
 		int k=minstep(i,j);
 		printf("%d",k);
	 }
	 printf("\n");
 }
	return 0;
}
