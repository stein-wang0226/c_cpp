//������ N ��̨�ף���ʼʱ���ڵ�0�㣬ÿ�����������������1������ K ��̨�ף����������� N ��̨�׹��ж������߷���





//�ݹ� TLE 
#include<stdio.h>
#include<string.h>
//�ɵõ��ƹ�ϵf(n) = f(n-1) + f(n-2) + f(n-3) + �� + f( max(0,n-k) ) 

int N,k;

int max(int a,int b)
{
	return a>b?a:b;
	
}


int f(int n)
{int s=0;
if (0==n)return 1;//0ҲӦ��Ϊһ������������ܴ�����0ֱ�ӵ� n�������n<k)) 
if (1==n)return 1;//
for(int i=n-1;i>=max(0,n-k);i--)s+=(f(i));//max��֤n<k�������0λ�ã�������ָ��� 
	s%=10003;
	return s;	
}

int main()
{ 
scanf("%d %d",&N,&k);
N%=100003;
printf("%d",f(N));
return 0;
}





//���� 
//#include<stdio.h>
//#include<string.h>
//int N,K;
//int a[100005];
//int main()
//{
//	a[0] = 1;
//	scanf("%d %d",&N,&K);
//	for(int i = 1;i <= N;i++){
//		for(int j = 1;j <= K && i-j >= 0;j++){
//			a[i] += a[i-j];
//			a[i] = a[i]%100003;
//		}
//	}
//	printf("%d\n",a[N]);
//	return 0;
//} 	
	
	
   

