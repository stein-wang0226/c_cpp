#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
char s[100];
int len;

int isvalid(char *s) {
	if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'||s[len-1]=='+'||s[len-1]=='-'||s[len-1]=='*'||s[len-1]=='/')
		return 0;
	for(int i=0; i<len-1; i++) {
		if(s[i]==s[i-1])return 0;
	}
	return 1;
}
int main() {
	while(1) {
		double m[100]= {0};
		int pos[100]= {0},sum; //�������λ���˳�λ���Ӽ�λ
		gets(s);
		len=strlen(s);
		if(isvalid(s)==0) {
			printf("error\n");
		}

		else {

			int cnt=0;
			for(int i=0; i<len; i++) {
				if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')pos[++cnt]=i;
			}
			pos[0]=-1;
			pos[cnt+1]=len;//�����ȱ�Ϊcnt+2
			for(int i=0; i<=cnt; i++) { //��cnt+1���� ,����a i~a i+1    pos0 -|m0 pos1 m1.....poscnt mcnt|pos cnt+1
				for(int j=pos[i]+1; j<=pos[i+1]-1; j++) { //����ÿ������
					m[i]=m[i]*10+(s[j]-'0');
				}
			}
			for(int i=1; i<=cnt; i++) { //��cnt�����Ŵ���
				if(s[pos[i]]=='*') {//  */,�������ǰһλ��0����һλ������
					m[i]=m[i-1]*m[i];
					m[i-1]=0;
				}
				if(s[pos[i]]=='/') {
					m[i]=m[i-1]/m[i];
					m[i-1]=0;
				}
			}
			char c='+';//���������˳�ǰ����,�� ����Ϊ+
			for(int i=1; i<=cnt; i++) { //+-
				if(s[pos[i]]=='+') {
					c='+';
					m[0]+=m[i];
				} else if(s[pos[i]]=='-') {
					c='-';
					m[0]-=m[i];
				} else if(s[pos[i]]=='*'||s[pos[i]]=='/') {
					if(c=='-')m[0]-=m[i];
					else  m[0]+=m[i];

				}
			}
			printf("%.3lf\n",m[0]);
		}
	}
	return 0;

}
