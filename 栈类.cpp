#include  <iostream>
#include  <algorithm>
using  namespace  std;

class  CStack
{
public  :
        CStack  ()    :m_sp(nullptr)          //构造函数
        {}
        ~CStack  ();                                  //析构函数
        CStack  (const  CStack  &rhs);
        CStack  &operator  =  (const  CStack  &rhs);
        CStack  (CStack  &&rhs);
        CStack  &operator  =  (CStack  &&rhs);

        void      push  (int  x);          //入栈
        bool      empty  ()  const;    //判栈空
        int        top  ()  const;        //非空时取栈顶元素
        void      pop  ();                          //非空时出栈
private  :
        struct  Node      //  内嵌结点类
        {
                Node():next  (nullptr)  {}    //结点建立时指针域值为nullptrptr
                int  data;
                Node  *next;
        };
        Node  *m_sp;                            //链表首指针
};

CStack::~CStack  ()
{
        //删除所有结点
        while  (m_sp  !=  nullptr)
        {
                Node  *p  =  m_sp;              //临时指针变量p
                m_sp  =  m_sp->next;
                delete  p;                          //删除p所指结点，删除后不可使用该结点
        }
}

void  CStack::push  (int  x)
{
        Node  *p  =  new  Node;                //动态分配1个结点
        p->data  =  x;
        p->next  =  m_sp;
        m_sp  =  p;
}

bool  CStack::empty  ()  const
{
        return  (m_sp  ==  nullptr);
}
int  CStack::top  ()  const
{
        return  m_sp->data;
}

void  CStack::pop  ()
{
        Node  *p  =  m_sp;
        m_sp  =  p->next;
        delete  p;
}
//将栈内所有元素出栈并显示
void  DumpStack  (CStack  &S)
{
        while  (!S.empty  ())
        {      int  x;
                x  =  S.top  ();
                cout  <<  x  <<  "  ";
                S.pop  ();
        }
        cout  <<  endl;
}

CStack ::CStack(const CStack&rhs){  // 拷贝构造
  if(rhs.m_sp==nullptr){  // 特判空栈
        this->m_sp=nullptr;
  }
  else{
  m_sp=new Node;
  m_sp->data=rhs.m_sp->data; // 头结点也有值
  Node *last=m_sp;//  当前末尾结点
  Node*cur= rhs.m_sp->next;  // 被复制的当前结点
  while(cur){
    Node *temp=new Node; // 新建结点
    temp->data=cur->data;  //复制元素
    last->next=temp;   // 挂在最后
    last=temp;   // 更新结尾
    cur=cur->next;   // 后移
  }
  last->next=nullptr;
  }
}

CStack::CStack(CStack&&rhs){ //移动构造
  m_sp=rhs.m_sp; // 移动头结点
  rhs.m_sp=nullptr;   // 销毁右值头结点
}

CStack&CStack::operator=(const CStack&rhs){//拷贝赋值
  CStack temp(rhs); //  移动构造
  Node *t=m_sp;
  m_sp=temp.m_sp;
  temp.m_sp=t;
  return *this;
}

CStack&CStack::operator=(CStack&&rhs){//移动赋值
  Node*p=this->m_sp; // 交换头结点  其他部分随之销毁
  this->m_sp=rhs.m_sp;
  rhs.m_sp=p;
  return *this;
}

//测试函数
int  main()
{
        CStack  S1,  S2;
        int        v,  x;

        while  (cin  >>  v  >>  x,v+x)
        {
                if  (v  ==  1)
                        S1.push  (x);
                else
                        S2.push  (x);
        }

        CStack  S3  (S1),  S4,  tmp1  (S1),  tmp2  =  S2;
        S4  =  S2;
        S1.push(100);
        S2.push(200);
        S3.push(300);
        S4.push(400);

        CStack    S6  =  S3,  S5  (std::move  (tmp1));  //指定移动构造
        S6  =  std::move  (tmp2);  //指定移动赋值
        S5.push(500);
        S6.push(600);

        DumpStack  (S1);
        DumpStack  (S2);
        DumpStack  (S3);
        DumpStack  (S4);
        DumpStack  (S5);
        DumpStack  (S6);
}