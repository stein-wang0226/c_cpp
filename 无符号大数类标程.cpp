#include  <iostream>
#include  <string>
#include  <cassert>
#include  <list>
using  namespace  std;

class  CUBigNumber  {
        friend  class  CBigNumber;
public:
        //无参构造无符号大数0
        CUBigNumber();
        //从字符串构造一个无符号大数
        explicit  CUBigNumber  (const  string  &str);
        explicit  operator  string  ()  const;  //转换成字符串
        //两个无符号大数相加
        CUBigNumber  operator  +  (const  CUBigNumber  &rhs)  const;
        //两个无符号大数相减
        CUBigNumber  operator  -  (const  CUBigNumber  &rhs)  const;
        //两个无符号大数相乘
        CUBigNumber  operator  *    (const  CUBigNumber  &rhs)  const;
        //两个无符号大数比较，小于、等于、大于时分别返回-1、0、1
        int  Compare(const  CUBigNumber  &rhs)  const;

        friend    istream  &  operator>>  (istream  &is,  CUBigNumber  &rhs);  //输入一个无符号大数
        friend    ostream  &  operator<<  (ostream  &os,  const  CUBigNumber  &rhs);  //输出无符号大数

private:
        //无符号大数规范表示，去除高位多余0，至少含一位数字
        void  _Normalize();
        //无符号大数乘1位数
        CUBigNumber  _MultiplyDigit  (int  digit)  const;
        //返回无符号大数中[start,  end)数字子序列组成的无符号大数
        //超出范围部分数字忽略，忽略后子序列不存在时返回0
        CUBigNumber  _FetchSub  (int  start,  int  end)  const;

private:
        list<int>  _lst;  //本类没有使用动态分配，无需定义拷贝控制函数
};

//无参构造无符号大数0
CUBigNumber::CUBigNumber()
{
        _lst.push_back(0);  //1位数  ：  0
}

//从字符串构造一个无符号大数
CUBigNumber::CUBigNumber  (const  string  &str)
{
        CUBigNumber  result;//结果先存放在临时对象里
        //跳过非数字字符
        for  (auto  it  =  str.begin();  it  !=  str.end();  ++it)  {
                char  ch  =  *it;
                if  (ch  <  '0'  ||  ch  >  '9')
                        throw  "Invalid  Number";//非数字字符
                result._lst.push_back(ch  -  '0');  //添加1位
        }
        result._Normalize();
        *this  =  std::move(result);  //读入的无符号大数转移赋值给当前变量
}

CUBigNumber::operator  string  ()  const  //转换成字符串
{
        string  str;  //构造一个空字符串

        assert(_lst.size()  >  0  );  //断言  ：  至少有1位数字
        for  (auto  it  =  _lst.begin();  it  !=  _lst.end();  ++it)
                str.push_back(*it  +  '0');//从高位到低位，添加每一位数字，需变成字符
        return  str;
}

//输入一个无符号大数
istream  &  operator  >>  (istream  &is,  CUBigNumber  &rhs)
{
        string    str;
        is  >>  str;
        rhs  =  std::move  (CUBigNumber  (str));  //构造的无符号大数转移赋值给rhs
        return  is;
}

//输出无符号大数
ostream  &  operator  <<  (ostream  &os,  const  CUBigNumber  &rhs)
{
/*
        assert(rhs._lst.size()  >  0  );  //断言  ：  至少有1位数字
        for  (auto  it  =  rhs._lst.begin();  it  !=  rhs._lst.end();  ++it)
                os  <<  *it;//从高位到低位，输出每一位数字
*/
        string  str  =  static_cast<string>(rhs);  //转换成字符串后输出
        os  <<  str;
        return  os;
}

//无符号大数规范表示，去除高位多余0，至少含一位数字
void  CUBigNumber::_Normalize()
{
        if  (_lst.size()  ==  0)
                _lst.push_back(0);  //1位数  ：  0
        while  (_lst.size()  >  1  &&  *_lst.begin()  ==  0)    //去除高位多余的0
                _lst.pop_front();  //丢弃最高位0
}
//无符号大数乘1位数
CUBigNumber  CUBigNumber::_MultiplyDigit  (int  digit)  const
{
        CUBigNumber  result;    //构造0
        if  (digit  ==  0)
                return  result;  //返回0

        result._lst.pop_front();  //丢弃唯一数字0
        int  iCarry  =  0;  //进位，初始0
        auto  it  =  _lst.rbegin();    //从低位开始处理
        while  (it  !=  _lst.rend())      //剩余位处理
        {
                int  x  =  *it  *  digit  +  iCarry;
                iCarry  =  x  /  10;  //新进位
                x  %=  10;                  //当前结果位
                result._lst.push_front(x);  //添加至结果最高位
                ++it;  //准备处理前一位
        }

        if  (iCarry  !=  0)  //最后进位处理
                result._lst.push_front(iCarry);  //添加至结果最高位
        return  result;  //返回结果对象
}

//返回无符号大数中[start,  end)数字子序列组成的无符号大数
//超出范围部分数字忽略，忽略后子序列不存在时返回0
CUBigNumber  CUBigNumber::_FetchSub  (int  start,  int  end)  const
{
        CUBigNumber  result;  //建立临时对象，值为  0
        int  i  =  0;
        auto  it  =  _lst.begin();    //从高位开始处理
        while  (i  <  start  &&  it  !=  _lst.end())
        {
                ++it;
                ++i;
        }
        while  (i  <  end  &&  it  !=  _lst.end())
        {
                result._lst.push_back  (*it);  //添加在尾部
                ++it;
                ++i;
        }
        result._Normalize  ();
        return  result;  //返回结果对象
}
//两个无符号大数比较，小于、等于、大于时分别返回-1、0、1
int  CUBigNumber::Compare(const  CUBigNumber  &rhs)  const
{
        if  (_lst.size()  <  rhs._lst.size  ())  //长度决定大小
                return  -1;
        if  (_lst.size()  >  rhs._lst.size  ())
                return  1;
        auto  it1  =  _lst.begin  ();  //从高位开始比较
        auto  it2  =  rhs._lst.begin  ();
        while  (it1  !=  _lst.end())  //从高位往低位，对应位比较
        {
                if  (*it1  >  *it2)
                        return  1;
                if  (*it1  <  *it2)
                        return  -1;
                ++it1;  ++it2;  //准备比较下一位
        }
        return  0;  //等长，且每一位相等
}

//两个无符号大数相加
CUBigNumber  CUBigNumber::operator  +  (const  CUBigNumber  &rhs)  const
{
        CUBigNumber  result;  //建立临时对象，值为  0
        result._lst.pop_front();  //丢弃唯一数字0
        int  iCarry  =  0;  //进位，初始0
        auto  it1  =  _lst.rbegin(),  it2  =  rhs._lst.rbegin();
        while  (it1  !=  _lst.rend()  &&  it2  !=  rhs._lst.rend())      //两数相同位处理
        {
                int  digit  =  *it1  +  *it2  +  iCarry;
                iCarry  =  digit  /  10;  //新进位
                digit  %=  10;                  //当前结果位
                result._lst.push_front(digit);  //添加至结果最高位
                ++it1;  ++it2;  //准备处理前一位
        }
        while  (it1  !=  _lst.rend())      //第一大数剩余位处理
        {
                int  digit  =  *it1  +  iCarry;
                iCarry  =  digit  /  10;  //新进位
                digit  %=  10;                  //当前结果位
                result._lst.push_front(digit);  //添加至结果最高位
                ++it1;  //准备处理前一位
        }
        while  (it2  !=  rhs._lst.rend())    //第二大数剩余位处理
        {
                int  digit  =  *it2  +  iCarry;
                iCarry  =  digit  /  10;  //新进位
                digit  %=  10;                  //当前结果位
                result._lst.push_front(digit);  //添加至结果最高位
                ++it2;  //准备处理前一位
        }
        if  (iCarry  !=  0)  //最后进位处理
                result._lst.push_front(iCarry);  //添加至结果最高位
        return  result;  //返回结果对象
}

//两个无符号大数相减
CUBigNumber  CUBigNumber::operator  -  (const  CUBigNumber  &rhs)  const
{
        assert(Compare(rhs)  >=  0);  //被减数（当前无符号大数）必须大于等于减数
        CUBigNumber  result;//建立临时对象，值为  0
        result._lst.pop_front();  //丢弃唯一数字0
        int  iCarry  =  0;  //借位，初始0
        auto  it1  =  _lst.rbegin(),  it2  =  rhs._lst.rbegin();
        while  (it1  !=  _lst.rend()  &&  it2  !=  rhs._lst.rend())      //两数相同位处理
        {
                int  digit  =  *it1  -  *it2  +  iCarry;
                iCarry  =  0;
                if  (digit  <  0)
                {
                        digit  +=  10;                  //当前结果位
                        iCarry  =  -1;  //新借位
                }
                result._lst.push_front(digit);  //添加至结果最高位
                ++it1;  ++it2;  //准备处理前一位
        }
        assert(it2  ==  rhs._lst.rend());
        while  (it1  !=  _lst.rend())      //第一大数剩余位处理
        {
                int  digit  =  *it1  +  iCarry;
                iCarry  =  0;
                if  (digit  <  0)
                {
                        digit  +=  10;                  //当前结果位
                        iCarry  =  -1;  //新借位
                }
                result._lst.push_front(digit);  //添加至结果最高位
                ++it1;  //准备处理前一位
        }
        assert(iCarry  ==  0);
        result._Normalize();
        return  result;//返回结果对象
}

//两个无符号大数相乘
CUBigNumber  CUBigNumber::operator  *    (const  CUBigNumber  &rhs)  const
{
        //递归终止条件
        if  (_lst.size()  ==  1)  //当前数是1位数
                return  rhs._MultiplyDigit  (*_lst.begin());
        else  if  (rhs._lst.size()  ==  1)  //rhs是1位数
                return  this->_MultiplyDigit  (*rhs._lst.begin());
        //  计算拆分长度
        int  m  =  _lst.size  ();
        int  n  =  rhs._lst.size();

        int  h  =  (m>  n?m:n)  /  2;
        /*  拆分为a,  b,  c,  d  */
        CUBigNumber  a,  b,  c,  d;

        a  =  _FetchSub  (  0,  m  -  h);  //高m-h位
        b  =  _FetchSub  (  m  -  h,  m);  //低h位
        c  =  rhs._FetchSub  (  0,  n  -  h);    //高m-h位
        d  =  rhs._FetchSub  (  n  -  h,  n);    //低h位
        //  计算z2,  z0,  z1,  此处的乘法使用递归
        CUBigNumber  z0,  z1,  z2;

        z2  =  a  *  c;  //z2  =  a  *  c;
        z0  =  b  *  d;  //z0  =  b  *  d;
        CUBigNumber    t1,  t2,  t3,t4,t5,  result;
        t1  =  a  +  b;        //t1  =  a+b
        t2  =  c  +  d;          //t2  =  c+d
        t3  =  t1  *  t2;  //t3  =  (a+b)*(c+d)
        t4  =  z0  +  z2;      //t4  =  z0  +  z2
        z1  =  t3  -  t4;      //z1  =  (a+b)*(c+d)  -  z2  -  z0

        int  i;
        for  (i=  0;  i  <  2  *h;  ++i)  //z2  *=  (10^(2*h))
                z2._lst.push_back(0);
        for  (i=  0;  i  <  h;  ++i)  //z1  *=  (10  ^  h)
                z1._lst.push_back  (0);
        t5  =  z2  +  z1;  //t5=  z2*10^2h  +  z1  *  10^h
        result  =  t5+  z0;  //result  =  z2*10^2h  +  z1  *  10^h  +z0
        return  result;
}
