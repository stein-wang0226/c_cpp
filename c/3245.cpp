//����������� �������Ӵ���  �����
#include <bits/stdc++.h>
#define ll  long long
#define INIF 2147483646
using namespace std;
int n,k;
char s1[2005];
char s2[2005];
ll dp[2005][1005];
int main() {
	memset(dp,0,sizeof dp);
	while(~scanf("%s %s",s1,s2)) { //input
		int len1=strlen(s1);
		int len2=strlen(s2);
		
		if(s1[0]==s2[0])dp[1][1]=1;//��1��ʼ����� 
		else dp[1][1]=0;
		
		for(int i=1;i<=len1;i++){//��� ****��� 
			for(int j=1;j<=len2;j++){
				if(i==1&&j==1)continue;
				if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1 ;//��ͬ+1 
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//����֮ǰ���ֵ 
			}
		}


	cout<<dp[len1][len2]<<endl;




	}

	return 0;
}
