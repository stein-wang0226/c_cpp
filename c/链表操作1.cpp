#include <bits/stdc++.h>
using namespace std;
struct num {
	int number;
	num*next;
};
num* creatchain(int n) {
	num *head ,*pnew,*ptail;//�����ͷ���ڵ㣬��β
	pnew=(num* )malloc(sizeof(num));//����ͷ�ڵ�
	cin>>pnew->number ;
	pnew->next=NULL;

	head=ptail=pnew;

	for(int i=1; i<n; i++) {
		pnew=(num*)malloc(sizeof(num));
		cin>>pnew->number;
		ptail->next=pnew;//***��ǰβ�ڵ�ָ���½ڵ�****
		ptail=pnew;//���� ��һβ�ڵ�
		ptail->next=NULL;
	}
	return head;//���������ͷ
}

num* insert(num *head) { //����Ϊ��ͷָ��
	num* pnew ,*cur,*pre;//ǰ����Ҫ
	pnew=(num*)malloc(sizeof(num));//����������ڵ�
	cin>>pnew->number;
	pnew->next=NULL;
	cur=head;//��ͷ��ʼѰ��

	if(cur->number>pnew->number) {//���뵽��ͷ
		pnew->next=head;
	} else {
		while(cur!=NULL&&pnew->number>cur->number) { //�����������λ��
			pre=cur;
			cur=cur->next;//***��һ��
		}
		if(cur ) {
			pnew->next=cur; //����ʱcurӦΪpnew ��һ��
			pre->next=pnew;//ǰ������
		}
		else{//cur Ϊ��� 
			pre->next=pnew;
			pnew->next=NULL; 
		}
	}
	return head;
}

void print(num *head) {
	num *p=head;

	while(p!=NULL) {
		cout<<p->number<<" ";
		p=p->next;
	}
}
int main() {
	int n=10;
	num* head=creatchain(n);//�����ڲ�����
	insert(head);
	print(head);

}
