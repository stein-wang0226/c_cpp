#include <bits/stdc++.h>

using namespace std;


class Cstring {
private:
    char *s;
    int len=0;
public:
    Cstring();
    Cstring(const Cstring&rhs);
    Cstring(Cstring&&rhs)noexcept;
//   重载
    Cstring& operator=(const char* rhs);  // 字符数组
    Cstring& operator=(const Cstring&rhs);
    Cstring& operator=(Cstring &&rhs)noexcept;
    Cstring substr(int pos,int length);//
    friend Cstring operator +(const Cstring &a,const Cstring &b);
    friend ostream& operator << (ostream& output,const Cstring& rhs);
    friend istream& operator >> (istream& input, Cstring& rhs);
    void input(Cstring&rhs);
    int size();
    void show();

} ;
Cstring::Cstring(){
    s=new char[1];
    len=0;
}
int Cstring::size(){
    len=strlen(s);
     s[len]='\0';
    return len;
}
Cstring::Cstring(const Cstring &rhs){//拷贝构造
    delete []s;
    s=new char[rhs.len+1];
    len=rhs.len;
    for(int i=0;i<len+1;i++)s[i]=rhs.s[i];    
     s[len]='\0';
}
Cstring::Cstring(Cstring &&rhs)noexcept{// 移动构造
    len=rhs.len;
    delete[]s;
    s=rhs.s;      
    rhs.s=NULL;   // 置空 防止内容被析构
}
Cstring& Cstring::operator=(const char*rhs){//复制构造字符数组
    len=strlen(rhs);
    delete []s;
    s=new char[len+1];
    for(int i=0;i<len;i++)s[i]=rhs[i];
    s[len]='\0';
    return *this;
}

Cstring& Cstring::operator=(const Cstring&rhs){ // 复制赋值类
    len=rhs.len;
    delete []s;
    s=new char[len+1];
    for(int i=0;i<len;i++)s[i]=rhs.s[i];
    s[len]='\0';
    return (*this);
}

Cstring& Cstring::operator=(Cstring &&rhs)noexcept{
    len=rhs.len;
    delete[]s;
    s=rhs.s;
    rhs.s=NULL;   //置空  防止内存随临时变量被析构
    return *this;
}

Cstring operator +(const Cstring &a,const Cstring&b){  //不能返回引用  （res）是局部变量
    Cstring res;
    res.len=b.len+a.len;
    res.s=new char[res.len+1];
    for(int i=0;i<a.len;i++)res.s[i]=a.s[i];
    for(int i=a.len;i<res.len+1;i++)res.s[i]=b.s[i-a.len];
    res.s[res.len]='\0';
    return res;
} 
Cstring Cstring::substr(int pos,int length){
    Cstring res;
    if(pos+length-1>len){
        return res;    // 直接返回空
    }
    res.len=length;
    res.s=new char[length+1];
    for(int i=0;i<length;i++){
        res.s[i]=s[i+pos-1];
    }
    res.s[length]='\0';
    return res;
}
void Cstring::show(){
    for(int i=0;i<len;i++){
        cout<<s[i];
    }
    cout<<endl;
}
istream& operator >> (istream& input, Cstring& rhs){
    input>>rhs.s;
    return input;
}

ostream& operator <<(ostream& output, const Cstring& rhs){
    output<<rhs.s;
    return output;
}
int main() {
    char S1[300],S2[300];
    scanf("%s %s",S1,S2);
    Cstring s[5];
    s[0]=S1;
    s[1]=S2;
    s[0].size();
    s[1].size();
    char ch;
    int q,w,e,r;
        while(cin>>ch)
      {
            if(ch=='P')
            {
                  cin>>q;
                  s[q-1].show();
            }
            else if(ch=='C')
            {
                  cin>>q>>w>>e;
                  s[e-1]=s[q-1]+s[w-1];
            }
            else if(ch=='A')
            {
                  cin>>q>>w;
                  s[w-1]=s[q-1];
            }
            else if(ch=='F')
            {
                  cin>>q>>w>>e>>r;
                  s[r-1]=s[q-1].substr(w+1,e);
            }

      }

    
  return 0;
}
