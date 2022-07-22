#include <bits/stdc++.h>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;


class UnsignedBigNumber{

public:
  UnsignedBigNumber(); // 默认构造函数（无参数）
  ~UnsignedBigNumber(); //析构函数
  UnsignedBigNumber & operator = (const UnsignedBigNumber &rhs); // 复制拷贝
  UnsignedBigNumber & operator = (UnsignedBigNumber &&rhs)noexcept;  // 移动赋值
  UnsignedBigNumber(const UnsignedBigNumber &rhs);  // 拷贝构造
  UnsignedBigNumber(UnsignedBigNumber &&rhs)noexcept;  // 移动构造

  void read();  // 数据读入
  void display()const;   //** 这样在cmp_ans_display函数中才能使用
  void display(int m)const; // 重载 显示+换行
  int cmp(const UnsignedBigNumber &rhs)const;  // 比较函数  》 《 =
  void cmp_and_display(const UnsignedBigNumber&rhs);
  UnsignedBigNumber plus (const UnsignedBigNumber &rhs);  // 加法
  UnsignedBigNumber sub(const UnsignedBigNumber &rhs); // 减

private:
  struct Node{
    int data;
    struct Node* pre;  // 
    struct Node* next;
    
  }*m_phead,*m_ptail;  //头结点空

int m_len;  ///  链表长度

};
//c参考 书本
// 默认构造函数
UnsignedBigNumber::UnsignedBigNumber(){
  m_phead=new Node;
  m_phead->next=m_phead->pre=NULL;
  m_ptail=NULL; //*置空
  // ptail 可以在读入后生成
  m_len=0;
}
/// 析构函数
UnsignedBigNumber::~UnsignedBigNumber(){
  while(m_phead){
    Node *p=m_phead;
    m_phead=p->next;
    delete p;
  } 
}
// 拷贝构造
UnsignedBigNumber::UnsignedBigNumber(const UnsignedBigNumber &rhs){
  m_phead=new Node;
  Node *cur =m_phead;  // 类中m_phead 对应链表最新结点
  Node *temp=rhs.m_phead->next;  // 用于被的结点
  while(temp!=NULL){
    Node *p=new Node;  // 新建结点
    p->data=temp->data; // 将值转移到新节点
    cur->next=p;   // 将新节点接上
    p->pre=cur;    // 更新pre
    cur=p;         // 更新当前结点
    temp=temp->next; // 后移
  }
cur->next=NULL;
m_ptail=cur; // 尾结点
m_len=rhs.m_len; // 长度
}

//拷贝赋值
UnsignedBigNumber & UnsignedBigNumber::operator = (const UnsignedBigNumber &rhs){
    UnsignedBigNumber tmp(rhs); //拷贝构造
  	Node *t = m_phead;       // 拷贝构造后直接交换头指针
  	m_phead = tmp.m_phead;
	  tmp.m_phead = t;
	  return *this;	
}

UnsignedBigNumber::UnsignedBigNumber(UnsignedBigNumber &&rhs)noexcept{// 移动构造
 m_phead=rhs.m_phead;
 rhs.m_phead=NULL;     // 传参 右值自动销毁
}
//移动赋值
UnsignedBigNumber & UnsignedBigNumber::operator = (UnsignedBigNumber&&rhs)noexcept{ 
  // 交换头指针
  Node *temp =this->m_phead;
  this->m_phead=rhs.m_phead;
  rhs.m_phead=temp;        
  //交换尾指针
  temp=this->m_ptail;
  this->m_ptail=rhs.m_ptail;
  rhs.m_ptail=temp;
  this->m_len=rhs.m_len;  // 长度
  //temp  rhs 自动析构
  return *this;
}

//读入函数
void UnsignedBigNumber::read(){
  string s;
  cin>>s;
  Node*cur=m_phead;
  int len=s.size();
  for(int i=0;i<len;i++){
    Node*temp=new Node;
    temp->data=s[i]-'0';
    cur->next=temp;
    temp->pre=cur;
    cur=temp;   // 下一个
  }
  m_ptail=cur;
  m_ptail->next=NULL;  
  m_len=len;
}

// 显示函数
void UnsignedBigNumber::display()const{
  Node*cur =m_phead->next;
  for(int i=0;i<m_len;i++){
    cout<<cur->data;
    cur=cur->next;
  }
}
//+换行
void UnsignedBigNumber::display(int m)const{
   Node*cur =m_phead->next;
  for(int i=0;i<m_len;i++){
    cout<<cur->data;
    cur=cur->next;
  }
  cout<<endl;
} 

int UnsignedBigNumber::cmp(const UnsignedBigNumber&rhs)const{
  if(m_len<rhs.m_len)return 0;  //<
  else if(m_len>rhs.m_len) return 1;  //>
  else {  //长度相同
    Node *cur1=m_phead->next;
    Node*cur2=rhs.m_phead->next;
    for(int i=1;i<=m_len;i++){
        if(cur1->data==cur2->data){
          cur1=cur1->next;
          cur2=cur2->next;
        }
        else if(cur1->data<cur2->data)return 0;
        else return 1;
    }
    return 2;   // ==
  }
}
//比较并显示
void UnsignedBigNumber::cmp_and_display(const UnsignedBigNumber &rhs){
  display(); //
  if(cmp(rhs)==0)cout<<" < ";
  else if(cmp(rhs)==1)cout<<" > " ;
  else cout<<" == ";
  rhs.display(1);  // 并换行
}

UnsignedBigNumber UnsignedBigNumber::plus(const UnsignedBigNumber&rhs){
  UnsignedBigNumber res;
  	Node *front = new Node;
	Node *s=front;	//为了和原来的链表具有一样的结构，最后释放这个空的尾结点； 
	Node *p=m_ptail;
	Node *q=rhs.m_ptail;
	int flag=0;
	for(int i=0;i<min(m_len,rhs.m_len);i++){
		Node *newnode = new Node;
		newnode->data=(p->data+q->data+flag)%10;
		flag=(p->data+q->data+flag)/10;
		newnode->next=front;
		front->pre=newnode;
		front=newnode;
		p=p->pre;
		q=q->pre;
	}
	if(m_len>min(m_len,rhs.m_len)){
		for (int i=1;i<=m_len-min(m_len,rhs.m_len);i++){
			Node *newnode = new Node;
			newnode->data=(p->data+flag)%10;
			flag=(p->data+flag)/10;
			newnode->next=front;
			front->pre=newnode;
			front=newnode;
			p=p->pre;
		}
		if(flag){
			Node *newnode = new Node;
			newnode->data=flag;
			newnode->next=front;
			front->pre=newnode;
			front=newnode;
			res.m_phead->next=front;
			front->pre= res.m_phead;
			res.m_len=m_len+1;
		}
		else{
			res.m_phead->next=front;
			front->pre= res.m_phead;
			res.m_len=m_len;
		}
	}
	else if(rhs.m_len>min(m_len,rhs.m_len)){
		for (int i=0;i<rhs.m_len-min(m_len,rhs.m_len);i++){
			Node *newnode = new Node;
			newnode->data=(q->data+flag)%10;
			flag=(q->data+flag)/10;
			newnode->next=front;
			front->pre=newnode;
			front=newnode;
			q=q->pre;
		}
		if(flag){
			Node *newnode = new Node;
			newnode->data=flag;
			newnode->next=front;
			front->pre=newnode;
			front=newnode;
			res.m_phead->next=front;
			front->pre= res.m_phead;
			res.m_len=rhs.m_len+1;
		}
		else{
			res.m_phead->next=front;
			front->pre= res.m_phead;
			res.m_len=rhs.m_len;
		}
	}
	else{
		if(flag){
			Node *newnode = new Node;
			newnode->data=flag;
			newnode->next=front;
			front->pre=newnode;
			front=newnode;
			res.m_phead->next=front;
			front->pre= res.m_phead;
			res.m_len=rhs.m_len+1;
		}
		else{
			res.m_phead->next=front;
			front->pre= res.m_phead;
			res.m_len=rhs.m_len;
		}
	}
	res.m_ptail=s->pre;
	s->pre->next = NULL;
	delete s;
	return res;
}

UnsignedBigNumber UnsignedBigNumber::sub(const UnsignedBigNumber &rhs){
	UnsignedBigNumber res;
	Node *front = new Node;
	Node *s=front;	//为了和原来的链表具有一样的结构，最后释放这个空的尾结点； 
	Node *p=m_ptail;
	Node *q=rhs.m_ptail;
	if(cmp(rhs)==1){
		for(int i=1;i<=rhs.m_len;i++){
			Node *newnode = new Node;
			if(p->data<q->data){
				newnode->data = p->data - q->data+10;
				p->pre->data-=1; 
			}
			else {newnode->data=p->data - q->data;}
			p=p->pre;
			q=q->pre;
			front->pre=newnode;
			newnode->next=front;
			front=newnode;
		}
		for(int i=1;i<=m_len-rhs.m_len;i++){
			Node *newnode = new Node;
			newnode->data=p->data;
			p=p->pre;
			front->pre=newnode;
			newnode->next=front;
			front=newnode;
		}
		//去除前导0
		res.m_len=m_len;
		Node *tmp=front;
		while(front->data==0){
			front=front->next;
			delete tmp;
			tmp = front;
			res.m_len--;
		}
	}
	else if(cmp(rhs)==0){ // <
		for(int i=0;i<m_len;i++){
			Node *newnode = new Node;
			if(q->data<p->data){
				newnode->data = q->data - p->data+10;
				q->pre->data-=1; 
			}
			else {newnode->data=q->data - p->data;}
			p=p->pre;
			q=q->pre;
			front->pre=newnode;
			newnode->next=front;
			front=newnode;
		}
		for(int i=0;i<rhs.m_len-m_len;i++){
			Node *newnode = new Node;
			newnode->data=q->data;
			q=q->pre;
			front->pre=newnode;
			newnode->next=front;
			front=newnode;
		}
		//去除前导0
		res.m_len=rhs.m_len;
		Node *tmp=front;
		while(front->data==0){
			front=front->next;
			delete tmp;
			tmp = front;
			res.m_len--;
		}
	}
	else{
		Node *newnode = new Node;
		newnode->data=0;
		front->pre=newnode;
		newnode->next=front;
		front=newnode;
		res.m_len=1;
	}
res.m_phead->next=front;
front->pre=res.m_phead; 
res.m_ptail=s->pre;
s->pre->next=NULL;
delete s;	
return res;
}






int main() {
UnsignedBigNumber a,b,c,d;
a.read();
b.read();
a.cmp_and_display(b);
c=a.plus(b);
d=a.sub(b);
c.display(1);
d.display(1);
  return 0;
}
