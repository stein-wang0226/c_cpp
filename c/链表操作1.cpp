#include <bits/stdc++.h>
using namespace std;
struct num {
	int number;
	num*next;
};
num* creatchain(int n) {
	num *head ,*pnew,*ptail;//定义表头，节点，表尾
	pnew=(num* )malloc(sizeof(num));//创建头节点
	cin>>pnew->number ;
	pnew->next=NULL;

	head=ptail=pnew;

	for(int i=1; i<n; i++) {
		pnew=(num*)malloc(sizeof(num));
		cin>>pnew->number;
		ptail->next=pnew;//***当前尾节点指向新节点****
		ptail=pnew;//更新 下一尾节点
		ptail->next=NULL;
	}
	return head;//返回链表表头
}

num* insert(num *head) { //参数为表头指针
	num* pnew ,*cur,*pre;//前后都需要
	pnew=(num*)malloc(sizeof(num));//创建待插入节点
	cin>>pnew->number;
	pnew->next=NULL;
	cur=head;//从头开始寻找

	if(cur->number>pnew->number) {//插入到表头
		pnew->next=head;
	} else {
		while(cur!=NULL&&pnew->number>cur->number) { //向后查找满足的位置
			pre=cur;
			cur=cur->next;//***下一个
		}
		if(cur ) {
			pnew->next=cur; //跳出时cur应为pnew 后一个
			pre->next=pnew;//前后都相连
		}
		else{//cur 为最后 
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
	num* head=creatchain(n);//都在内部输入
	insert(head);
	print(head);

}
