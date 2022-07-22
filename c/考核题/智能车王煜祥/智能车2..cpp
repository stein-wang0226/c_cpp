// 想到方法用递归算总数，但输出不了矩阵，先用十个for->(韩学长说的)
#include<stdio.h>
//long long sum(int a){
//	long long cnt;
//	for(int i=1;1<=a;i++)
//	cnt+=i*(a+1-i);
//	return 5;
//}
int main(){ 
long long cnt;
	for(int i=1;1<=5;i++)
	cnt+=i*(5+1-i);
 printf("%lld",cnt);
return 0;
}






