#include <bits/stdc++.h>

using namespace std;


// 有理数 类
class RationalNumber{


public:
    RationalNumber(); // 构造初始化
    RationalNumber(int x,int y); // 构造初始化
    // 可用友元
    RationalNumber& operator =(const RationalNumber &rhs);
    RationalNumber operator+(const RationalNumber &rhs);
    RationalNumber operator-(const RationalNumber &rhs);
    RationalNumber operator*(const RationalNumber &rhs);
    RationalNumber operator/(const RationalNumber &rhs);
    friend istream &operator >>(istream& input, RationalNumber&rhs);
    void output();
private:
    int mole;   //分子
    int demo;   // 分母
    void simplify();  // 约分处理
    //char sign=1;    // 正负号
};

RationalNumber::RationalNumber(){
    demo=0;
    mole=0;
}
RationalNumber::RationalNumber(int x,int y ){
    mole=x;
    demo=y;
    simplify();
}
void RationalNumber::simplify(){// 约分化简
    if(mole==0){return; }
    if(mole<0&&demo<0||mole>0&&demo<0){mole*=-1;demo*=-1;}
    int gcd=__gcd(abs(mole),abs(demo));
    mole/=gcd;
    demo/=gcd;
}
RationalNumber&RationalNumber::operator=(const RationalNumber&rhs){  //复制赋值
    this->mole=rhs.mole;
    this->demo=rhs.demo;
    return *this;
}

RationalNumber RationalNumber::operator+(const RationalNumber &rhs){// 通分相加约分
RationalNumber res;
int a=mole;
int b=demo;
int c=rhs.mole;
int d=rhs.demo;
res.demo=b*d;
res.mole=a*d+b*c;
res.simplify();
return res;
}

RationalNumber RationalNumber::operator-(const RationalNumber&rhs){
RationalNumber res;
int a=mole;
int b=demo;
int c=rhs.mole;
int d=rhs.demo;
res.demo=b*d;
res.mole=a*d-b*c;
res.simplify();
return res;
}
RationalNumber RationalNumber::operator*(const RationalNumber&rhs){
RationalNumber res;
int a=mole;
int b=demo;
int c=rhs.mole;
int d=rhs.demo;
res.mole=a*c;
res.demo=b*d;
res.simplify();
return res;
}
RationalNumber RationalNumber::operator/(const RationalNumber&rhs){
RationalNumber res;
int a=mole;
int b=demo;
int c=rhs.mole;
int d=rhs.demo;
res.mole=a*d;
res.demo=b*c;
res.simplify();
return res;
}

void RationalNumber::output(){
    if(demo==1){
    
        cout<<mole;
    }
    else{
        cout<<mole<<'/'<<demo;
    }
}

istream& operator >>(istream&input, RationalNumber&rhs){  // 重载输入
    input>>rhs.mole>>rhs.demo;
    rhs.simplify();
    return input;
}


int main() {
    RationalNumber a,b;
    cin>>a>>b;
    a.output();cout<<endl;
    b.output();cout<<endl;
    RationalNumber c,d,e,f;
    c=a+b;
    d=a-b;
    e=a*b;
    f=a/b;
    c.output();printf("\t");
    d.output();printf("\t");
    e.output();printf("\t");
    f.output();printf("\t");

  return 0;
}
