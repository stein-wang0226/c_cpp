#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main() {
	int pos[100]= {0},eqlpos;
	double kl[100]= {0},kr[100]= {0},cl[100]= {0},cr[100]= {0},Kl=0,Kr=0,Cl=0,Cr=0;
	double ans;//k 为系数，c为常数
	char var;
	char s[200];
	cin>>s;
	int n=strlen(s);
//	printf("%d\n",n);
	int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	int eqlorder;//等号位次
	for(int i=0; i<n; i++) {
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')pos[++cnt]=i;//查找符号位
		if(s[i]=='=') {
			eqlpos=i;
			eqlorder=cnt;
		}
		if(s[i]>='a'&&s[i]<='z')var=s[i];//get name
	}
	pos[cnt+1]=n;
	//假象符号位，便于处理
	int m=0;//临时储存数
	if(s[0]=='-') {

		for(int i=1; i<=eqlorder-1; i++) {
			m=0;                       //left
			for(int j=pos[i]+1; j<=pos[i+1]-1; j++) {
				if(s[j]>='0'&&s[j]<='9') {
					m=m*10+(s[j]-'0') ;
				} else {
					if(s[pos[i]]=='-')	{
						if(m==0)m=1;
						kl[++cnt1]=-1*m;
						break;
					} else {
						if(m==0)m=1;
						kl[++cnt1]=m;
						break;
					}
				}
				if(j==pos[i+1]-1) {
					if(s[pos[i]]=='-')	cl[++cnt3]=-1*m;
					else cl[++cnt3]=m;
				}
			}
		}
	} else {
		pos[0]=-1;
		for(int l=0; l<=eqlorder-1; l++) {
			m=0;

			for(int j=pos[l]+1; j<=pos[l+1]-1; j++) {
				if(s[j]>='0'&&s[j]<='9') {
					m=m*10+(s[j]-'0') ;
				} else  {
					if(l>0&&s[pos[l]]=='-') {
						if(m==0)m=1;
						kl[++cnt1]=-1*m;
						break;
					} else {
						if(m==0)m=1;
						kl[++cnt1]=m;
						break;
					}
				}
				if(j==pos[l+1]-1) {
					if(s[pos[l]]=='-')cl[++cnt3]=-1*m;
					else cl[++cnt3]=m;
				}
			}
		}
	}



	if(s[pos[eqlorder]+1]!='-') {
		for(int i=eqlorder; i<=cnt; i++) {//right
			m=0;
			for(int j=pos[i]+1; j<=pos[i+1]-1; j++) {
				if(s[j]>='0'&&s[j]<='9') {
					m=m*10+(s[j]-'0') ;
				} else {
					if(s[pos[i]]=='-')	{
						if(m==0)m=1;
						kr[++cnt2]=-1*m;
						break;
					} else {
						if(m==0)m=1;
						kr[++cnt2]=m;
						break;
					}
				}
				if(j==pos[i+1]-1) {
					if(s[pos[i]]=='-') {
						cr[++cnt4]=-1*m;
					} else {
						cr[++cnt4]=m;
					}
				}
			}
		}
	} else {
		for(int i=eqlorder+1; i<=cnt; i++) {//right
			m=0;
			for(int j=pos[i]+1; j<=pos[i+1]-1; j++) {
				if(s[j]>='0'&&s[j]<='9') {
					m=m*10+(s[j]-'0') ;
				} else  {
					if(s[pos[i]]=='-') {
						if(m==0)m=1;
						kr[++cnt2]=-1*m;
						break;
					} else {
						if(m==0)m=1;
						kr[++cnt2]=m;
						break;
					}
				}
				if(j==pos[i+1]-1) {
					if(s[pos[i]]=='-')cr[++cnt4]=-1*m;
					else cr[++cnt4]=m;
				}
			}
		}
	}
	for(int i=1; i<=cnt1; i++)Kl+=kl[i];//累计 kl kr cl cr的值
	for(int i=1; i<=cnt2; i++)Kr+=kr[i];
	for(int i=1; i<=cnt3; i++)Cl+=cl[i];
	for(int i=1; i<=cnt4; i++)Cr+=cr[i];

	ans=(Cr-Cl)/(Kl-Kr);
	if (ans<1e-10&&ans>-1e-10) ans=0;
	printf("%c=%.3lf",var,ans);


	return 0;
}
