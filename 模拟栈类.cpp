#include <bits/stdc++.h>
#define LOCAL
#define endl "\n"
//# pragma GCC optimize(3) 
//#define int long long
using namespace std;

class Stack{
    public:
    Stack(){
        a.clear();
        m_size=0;
    }
    void push(int x){
        a.push_back(x);
        m_size++;
    }
    void pop(){
        a.pop_back();
        m_size--;
    }
    int top(){
        return a[m_size-1];
    }
    bool empty(){
        if(m_size==0)return true;
        else return false;
    }
    private:
    vector<int>a;
    int m_size;
};

int main(){
Stack stk1,stk2;
int a,b;
while(cin>>a>>b){
    if(a==1)stk1.push(b);
    else if (a==2)stk2.push(b);
}
while(!stk1.empty()){
    int u=stk1.top();
    stk1.pop();
    cout<<u<<" ";
}
cout<<endl;
while(!stk2.empty()){
    int u=stk2.top();
    stk2.pop();
    cout<<u<<" ";
}

    return 0;
}
