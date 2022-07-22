//string 类
#include<iostream>
#include<cstring>
using namespace std;

class CString{
    private:
      char *m_s;
      int m_len;
      explicit CString(int len){ //构造长度为len
        m_s=new char[len+1];
        m_len=len;
      }
    public:
        CString(); //无参构造
        CString (const char *str); //传统字符串构造
        ~CString(){
            delete [] m_s;
        }

        CString (const CString &rhs); //拷贝构造
        CString (CString &&rhs)noexcept; //移动构造
        CString &operator =(const CString &rhs); //构造赋值
        CString &operator =(CString &&rhs)noexcept; //移动赋值

        friend ostream &operator<<(ostream &out,const CString &rhs); //重载输出
        //friend istream &operator>>(istream &in,const CString &rhs); // 输入无法确定长度  不使用
        friend CString operator +(const CString &S1,const CString &S2);// 字符串连接

        CString  substr(int start,int len); //取子串
        char & operator [] (int index); //重载取下标运算符  可用于左值
        const char& operator [](int index)const ; //下标运算符 ，只能用于右值
        operator const char *()const;
};

//无参构造 空串
CString ::CString(){
    m_len=0;
    m_s=new char[1];
    m_s[0]='\0';
}

//传统字符串构造
CString ::CString(const char*str){
    m_len=strlen(str);
    m_s=new char[m_len+1];
    strcpy(m_s,str);
}

//拷贝构造
CString::CString (const CString &rhs):m_s(NULL){ //m_s 初始化空
    m_len=rhs.m_len;
    m_s=new char[m_len+1];
    strcpy(m_s,rhs.m_s);
}

//移动构造
CString::CString ( CString &&rhs)noexcept{
    m_len=rhs.m_len;
    m_s=rhs.m_s;
    rhs.m_s=NULL ; //rhs 资源已转移 不可在析构时释放
}
//复制赋值 ***
CString &CString::operator =(const CString &rhs){ //返回应用 实现连续赋值
    CString tmp(rhs);
    swap(m_s,tmp.m_s);   //最安全    之后析构rhs
    swap(m_len,tmp.m_len); 
    return *this;
}

//移动赋值
CString &CString ::operator =(CString &&rhs)noexcept{
    //swap 交换两个对象值  ，当前对象的资源交给rhs 析构时释放
    swap(m_s,rhs.m_s);
    swap(m_len,rhs.m_len);
    return *this;
}

//取子串
CString CString::substr(int start ,int len){
    CString temp(len);
    for(int i=start;i<start+len;i++){
        temp.m_s[i-start]=m_s[i];
    }
    temp.m_s[len]='\0';
    return temp;
}

//插入运算符重载
ostream & operator <<(ostream &out ,const CString &rhs){
    out<<rhs.m_s;
    return out;
}
//连接
CString operator +(const CString &S1,const CString &S2){
    CString temp(S1.m_len+S2.m_len);
    strcpy(temp.m_s,S1.m_s);
    strcat(temp.m_s,S2.m_s);

    return temp;
}

//取下标运算符 只用于右值
const char&CString ::operator[](int index )const{
    if(index<0||index>m_len){
        static char c;
        return c; //返回空字符
    }
    return m_s[index];
}
//可用于左值 --嵌套
char& CString::operator[](int index){
         if(index<0||index>m_len){
        static char c;
        return c; //返回空字符
    }
    return m_s[index];
}
// **转换运输符
CString::operator const char*()const{
    return m_s;
}

//
int main(){


CString s1="123",s2("124");
CString s3=s1+s2;
cout<<s1<<endl;
cout<<s2<<endl;
cout<<s3<<endl;



}