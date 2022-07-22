#include<stdio.h>
#include<string.h>
int a[50],b[50],c[100];
int cnt=0;//桌上牌数
int pos;// 重复数位置
int re_pos(int m) {//传入a1 b1判断重复
	if (1==cnt)return 0;//第一位未进入循环 
	for(int i=1; i<cnt; i++) {
		if(c[i]==m) return  i;//返回
		  
	}
	return 0;//未找到返回0
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]); //input ,从1开始
	for(int j=1; j<=n; j++)scanf("%d",&b[j]);
	int l1,l2;//储存两人当前手牌数
	l1=l2=n;
	while(l1&&l2) {
		l1--;
		cnt++;
		int num=cnt;//存放cnt
		c[cnt]=a[1];//a打出一张
		
		for(int i=2; i<=l1+1; i++) {
			a[i-1]=a[i] ;//全部前移一位
		}
		a[l1+1]=0;//末尾清零 
		 pos= re_pos(c[cnt]);
		if (pos) {
			for(int i=num; i>=pos; i--) { //执行取牌操作
				a[++l1]=c[i];
				c[i]=0;
				cnt--;
			}
		}
		if(!(l1&&l2))break;

		l2--;
		cnt++;
		c[cnt]=b[1];//b打出一张
		for(int i=2; i<=l2+1; i++) {
			b[i-1]=b[i] ;//全部前移一位
		}
		b[l2+1]=0;//末尾清零 
		num=cnt;//更新cnt
		pos= re_pos(c[cnt]);// 重复数位置
		if (pos) {
			for(int i=num; i>=pos; i--) { //执行取牌操作
				b[++l2]=c[i];
				c[i]=0;
				cnt--;
			}
		}
	}
	if(l1) {
	printf("涵涵\n手上的牌为：");
	for(int i=1;i<=l1;i++)printf("%d ",a[i]) ;
	}
	else {
	printf("昊昊\n手上的牌为：");
	for(int i=1;i<=l2;i++)printf("%d ",b[i]) ;
	}

	return 0;
}
