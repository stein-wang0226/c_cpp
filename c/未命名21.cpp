#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main() {
	int pos[100],eqlpos,kl[100],kr[100],cl[100],cr[100],Kl,Kr,Cl,Cr;
	double ans;//k 为系数，c为常数
	char var;
	string s;
	cin>>s;
	
	int n=0;//s.size();
	printf("%d\n",n);
	int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	int eqlorder;//等号位次
	for(int i=0; i<n; i++) {
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')pos[++cnt]=i;//查找符号位
		if(s[i]=='=') {
			eqlpos=i;
			eqlorder=cnt;
		}
		if(s[i]>='a'||s[i]<='z')var=s[i];//get name
	}
	pos[cnt+1]=n;//假象符号位，便于处理
	int m=0;//临时储存数
	for(int i=1; i<=eqlorder-1; i++) {
		m=0;                       //left
		for(int j=pos[i]+1; j<=pos[i+1]-1; j++) {
			if(s[j]>='0'&&s[j]<='9') {
				m=m*10+(s[j]-'0') ;
			} else {
				if(pos[i]=='+')	kl[++cnt1]=m;
				else kl[++cnt1]=-1*m;
			}
			if(j==pos[i+1]-1) {
				if(pos[i]=='+')	cl[++cnt3]=m;
				else cl[++cnt3]=-1*m;
			}
		}
	}

	for(int i=eqlorder; i<=cnt; i++) {//right
		m=0;
		for(int j=pos[i]+1; j<=pos[i+1]-1; j++) {
			if(s[j]>='0'&&s[j]<='9') {
				m=m*10+(s[j]-'0') ;
			} else {
				cr[++cnt2]=m;
			}
			if(j==pos[i+1]-1)kr[++cnt4]=m;
		}
	}
	for(int i=1; i<=cnt1; i++)Kl+=kl[i];//累计 kl kr cl cr的值 
	for(int i=1; i<=cnt2; i++)Kr+=kr[i];
	for(int i=1; i<=cnt3; i++)Cl+=cl[i];
	for(int i=1; i<=cnt4; i++)Cr+=cr[i];
	
	ans=(cr-cl)/(kl-kr);
	printf("%c=%lf",var,ans); 


	return 0;
}
