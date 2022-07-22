#include <bits/stdc++.h>

using namespace std;

template<typename type>
class Queue{
    private:
        deque<type>m_que;
        type m_front;
        type m_back;
        int m_size;
    public:
        Queue(); //参数构造
        Queue &operator=(const Queue&rhs); //复制赋值   这里用Queue简化代替Queue<type>  （class 作用域内）
        void push(type rhs);
        void pop();
        type front();
        type back();
        int size();
};

template<typename type>
Queue<type>::Queue(){
    m_size=0;
}

template<typename type>
Queue<type>& Queue<type>::operator=(const Queue<type>&rhs){ //复制赋值 
    m_que=rhs.m_que;
    m_front=rhs.m_front;
    m_back=rhs.m_back;
    m_size=rhs.m_size;
    return *this;
}

template<typename type>
void Queue<type>::push(type rhs){
    m_size++;
    m_que.push_back(rhs);
    m_back=m_que.back();
    m_front=m_que.front();
}


template<typename type>
void Queue<type>::pop(){
    m_size--;
    cout<<this->m_front<<" ";
    m_que.pop_front();
    if(m_size)m_back=m_que.back();  //***
    if(m_size)m_front=m_que.front();//
}

template<typename type>
type Queue<type>::front(){
    return m_front;
}
template<typename type>
type Queue<type>::back(){
    return m_back;
}
template<typename type>
int Queue<type>::size(){
    return this->m_size;
}
int main(){

    cout<<"Start:"<<endl;
    string ty;
    cin>>ty;
    int n ;
    if(ty=="int"){
        Queue<int>q[4];
        cin>>n;
        int id,x,id2;
        string op;
        while(n--){
            cin>>op;
            if(op=="push"){
            cin>>id>>x;
            q[id-1].push(x);
            }
            else if(op=="pop"){
                cin>>id;
                q[id-1].pop();
            }
            else if(op=="assign"){
                cin>>id>>id2;
                q[id2-1]=q[id-1];
            }
        }
       q[3]=q[0];
        cout<<endl;
       cout<<"Final:"<<endl;
        for(int i=0;i<4;i++){
            while(q[i].size()){
                q[i].pop();
            }
            cout<<endl;
        }
    }
    else if(ty=="string"){
        Queue<string>q[4];
        cin>>n;
        int id,id2;
        string x;
        string op;
        while(n--){
            cin>>op;
            if(op=="push"){
            cin>>id>>x;
            q[id-1].push(x);
            }
            else if(op=="pop"){
                cin>>id;
                q[id-1].pop();
            }
            else if(op=="assign"){
                cin>>id>>id2;
                q[id2-1]=q[id-1];
            }
        }
        q[3]=q[0];
        cout<<endl;
        cout<<"Final:"<<endl;
        for(int i=0;i<4;i++){
            while(q[i].size()){
                q[i].pop();
            }
            cout<<endl;
        }
    }
    return 0;
}