#include<stdio.h>
#include<string.h>
int a[50],b[50],c[100];
int cnt=0;//��������
int pos;// �ظ���λ��
int re_pos(int m) {//����a1 b1�ж��ظ�
	if (1==cnt)return 0;//��һλδ����ѭ�� 
	for(int i=1; i<cnt; i++) {
		if(c[i]==m) return  i;//����
		  
	}
	return 0;//δ�ҵ�����0
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]); //input ,��1��ʼ
	for(int j=1; j<=n; j++)scanf("%d",&b[j]);
	int l1,l2;//�������˵�ǰ������
	l1=l2=n;
	while(l1&&l2) {
		l1--;
		cnt++;
		int num=cnt;//���cnt
		c[cnt]=a[1];//a���һ��
		
		for(int i=2; i<=l1+1; i++) {
			a[i-1]=a[i] ;//ȫ��ǰ��һλ
		}
		a[l1+1]=0;//ĩβ���� 
		 pos= re_pos(c[cnt]);
		if (pos) {
			for(int i=num; i>=pos; i--) { //ִ��ȡ�Ʋ���
				a[++l1]=c[i];
				c[i]=0;
				cnt--;
			}
		}
		if(!(l1&&l2))break;

		l2--;
		cnt++;
		c[cnt]=b[1];//b���һ��
		for(int i=2; i<=l2+1; i++) {
			b[i-1]=b[i] ;//ȫ��ǰ��һλ
		}
		b[l2+1]=0;//ĩβ���� 
		num=cnt;//����cnt
		pos= re_pos(c[cnt]);// �ظ���λ��
		if (pos) {
			for(int i=num; i>=pos; i--) { //ִ��ȡ�Ʋ���
				b[++l2]=c[i];
				c[i]=0;
				cnt--;
			}
		}
	}
	if(l1) {
	printf("����\n���ϵ���Ϊ��");
	for(int i=1;i<=l1;i++)printf("%d ",a[i]) ;
	}
	else {
	printf("��\n���ϵ���Ϊ��");
	for(int i=1;i<=l2;i++)printf("%d ",b[i]) ;
	}

	return 0;
}
