//向量类模板实现及异常抛出
#include <bits/stdc++.h>
using namespace std;

//异常对象类
class CException:public exception{
    private:
        string m_errMsg;
        public:
        //构造
            CException (string errMsg,int i):m_errMsg(errMsg){
                stringstream stream;   //字符串流  （与输入输出流类似，储存功能）
                stream<<i;              //将整型i插入字符串流
                string str;             //从字符串流中提取字符串赋值到str
                stream>>str;
                m_errMsg+=str;          //拼接
            }
            const char*what()const noexcept{ //虚函数what 返回异常类型
                return m_errMsg.c_str();
            }
};
template<class T>
class CVector{
    private:
        T *m_pBuffer; //存放元素缓冲取指针
        int m_size,m_bufferSize;    // 存放元素个数，缓冲区大小
    public :
        //构造
        CVector():m_pBuffer(nullptr ),m_size(0),m_bufferSize(0){}
        CVector(int n):m_pBuffer(nullptr),m_size(n),m_bufferSize(n){
            if(m_bufferSize>0)
                m_pBuffer=new T[m_bufferSize]; //动态分配内存
        }
        //析构
        ~CVector(){
            delete []m_pBuffer;
        }
        CVector(const CVector&rhs); //复制构造
        CVector(CVector&&rhs);              //移动构造
        CVector&operator =(const CVector&rhs); //复制赋值
        CVector &operator =(CVector &&rhs); //移动赋值
        void push_back(const T&rhs); //
        T &at(int i){ //类似下标运算符
            if(i<0||i>=m_size){
                string errMsg("invalid index"); //下标出错
                throw CException(errMsg ,i); //抛出异常
            }
            return m_pBuffer[i];
        }
        T &operator []( int i){
            return m_pBuffer[i]; //直接返回 为提高效率不进行越界检查
        }
        int size()const {
            return m_size;
        }
};

template<class T>
void CVector<T>::push_back(const T &rhs){
    if(m_bufferSize<=m_size){//空间不足 ，作必要扩容
        CVector<T>tmpVec;    //在临时对象中扩容 这样即使有异常也能保证原向量状态不变
        tmpVec.m_bufferSize=m_bufferSize*2+1; //每次扩容一倍***
        tmpVec.m_pBuffer=new T[tmpVec.m_bufferSize];
        tmpVec.m_size=m_size;
        for(int i=0;i<m_size;i++)
            tmpVec.m_pBuffer[i]=m_pBuffer[i];
            //临时对象赋值  扩容后
            //与当前向量交换
            swap(*this ,tmpVec);
    }
    m_pBuffer[m_size++]=rhs;
}

template<class T> //:: 后可以省略<T>
CVector<T>::CVector(const CVector&rhs):m_pBuffer(nullptr),m_size(rhs.m_size),m_bufferSize(rhs.m_bufferSize)
//复制构造
{ 
    if(m_bufferSize==0)
        return ;
    m_pBuffer=new T[m_bufferSize];
    for(int i=0;i<m_size;i++)
        m_pBuffer[i]=rhs.m_pBuffer[i];
}
template <class T>//移动构造
CVector <T>::CVector(CVector&&rhs):m_pBuffer(rhs.m_pBuffer),m_size(rhs.m_size),m_bufferSize(rhs.m_bufferSize){
	//rhs 资源已转移 不可再释放
	rhs.m_pBuffer=nullptr;
	rhs.m_size-0;
	rhs.m_bufferSize=0;
}


template<class T>
CVector<T>& CVector<T>::operator=(const CVector&rhs){ //复制赋值
    CVector<T>tmpVec(rhs); //拷贝构造临时对象，异常也能保证原向量状态不变
    //交换当前向量和临时向量 ，当前向量交由临时对象释放
    swap(m_pBuffer,tmpVec.m_pBuffer); swap(m_bufferSize,tmpVec.m_bufferSize);swap(m_size,tmpVec.m_size);
    return *this;
}

template<class T>
CVector<T>& CVector<T>::operator=(CVector&&rhs){ //移动赋值
    //交换当前向量和rhs ，当前向量交由rhs释放
  //swap(*this,rhs) 会形成死递归 ，因为swap本身需要移动赋值和移动拷贝
  swap(m_pBuffer,rhs.m_pBuffer);
  swap(m_bufferSize,rhs.m_bufferSize);
  swap(m_size,rhs.m_size);
  return *this;
}


//测试程序指令解析算法  模板函数
template<class T>
void Parse(int size){
    CVector <T> V(size);
    string cmd;
    T x;
    int index;
    while(cin>>cmd){
            //异常发生时正在执行的指令失败，下一条指令不受影响；
            try{
                if(cmd=="quit")
                    break;
                else if(cmd=="push") //
                {
                    cin>>x;V.push_back(x);
                }
                else if(cmd=="put"){//放--赋值
                    cin>>index>>x;
                    V.at(index)=x;
                }
                
            }

            catch(exception &ex){
                cout<<" "<<ex.what(); //输出异常类型
            }
            cout<<endl;
    }
}

int main(){

    string typeStr;
    while(cin>>typeStr){
        int size;
        if(typeStr=="int"){
            Parse<int>(size);
        }
        else
        Parse <string>(size);
    }
    return 0;
}










