#include <bits/stdc++.h>
using namespace std;
class CPoint{
	public:
		int m_x;
		int m_y;
    CPoint ();
    CPoint(int x,int y):m_x(x),m_y(y){};
};
CPoint::CPoint(){
    m_x=0,m_y=0;
}
class CShape{
	public:
		virtual bool Hitln(CPoint pos);
	//	virtual ~CShape();//
};
bool CShape::Hitln(CPoint pos){ //
	if(pos.m_x>0&&pos.m_y>0)return true;
	return false;
}
class CRectangle :public CShape{
	private :
		CPoint m_pos;
		int m_iWidth;
		int m_Height;
	public :
		CRectangle(CPoint pos,int x,int y);
	    bool Hitln(CPoint pos);
		
};
CRectangle::CRectangle(CPoint pos,int x,int y){
    m_pos=pos;
    m_iWidth=x;
    m_Height=y;
}
bool CRectangle::Hitln(CPoint pos){
    if(pos.m_x>=m_pos.m_x&&pos.m_x<=m_pos.m_x+m_iWidth&&pos.m_y>=m_pos.m_y&&pos.m_y<=m_pos.m_y+m_Height){
        return true;
    }
    return false;
}
class CCircle  :public CShape{
	private:
		CPoint m_center;
		double m_dR;
	public :
		CCircle(CPoint center,double dR);
	     bool Hitln (CPoint pos);
};
CCircle::CCircle(CPoint center,double dR){
    m_center=center;
    m_dR=dR;
}
bool CCircle::Hitln(CPoint pos){
    double  dis=sqrt((pos.m_x-m_center.m_x)*(pos.m_x-m_center.m_x)+(pos.m_y-m_center.m_y)*(pos.m_y-m_center.m_y));
    return dis<=m_dR;
}   

class CUIControl{
    protected:
        string m_name;
        CShape* m_pShape;
    public :
        virtual void Click()const;
        CUIControl(){
            m_name="";   //默认构造
        }; //构造
        CUIControl(string name):m_name(name){}; //构造
        bool HitTest(CPoint pos);
        void Setshape (CShape* pShape);
        virtual ~CUIControl(){delete m_pShape;}
};
void CUIControl::Setshape (CShape* pShape){
	m_pShape=pShape;
}
 
bool CUIControl :: HitTest(CPoint pos){
	return m_pShape->Hitln(pos);
}
void CUIControl::Click()const{
    cout<<m_name<<" "<<"Clicked"<<endl;
}  


class CMenu: public CUIControl{
    public:
        CMenu(string name):CUIControl(name){};
        void Click ()const;  //原本就是虚函数
};
	void CMenu::Click()const{
	    cout<<"menu-"<<m_name<<" "<<"Clicked"<<endl;
	}

class CButton: public CUIControl{
    public:
    CButton(string name):CUIControl(name){};
    void Click ()const;
};
void CButton::Click()const{
    cout<<"button-"<<m_name<<" "<<"Clicked"<<endl;
}
int main() {
int T;
cin>>T;
vector<CUIControl*>vec;//存基类指针  可以指向派生类
while(T--){
	string a,b,c;
	cin>>a>>b>>c;
	if(a=="menu"){
        CMenu *menu = new  CMenu(b);//**动态分配 才能运用动态多态性
		if(c=="rectangle"){
			int x,y,w,h;
			cin>>x>>y>>w>>h;
			CPoint pos(x,y);
            CRectangle *rec=new CRectangle(pos,w,h);//** 动态分配 
            menu->Setshape(rec); //
            vec.push_back(menu);
		}
		else{
			int x,y;double r;
			cin>>x>>y>>r;
			CPoint pos(x,y);
			CCircle *cir=new CCircle (pos,r);  //new   无括号
            menu->Setshape(cir); //
            vec.push_back(menu);
		}
	}
	else{
		CButton *button=new CButton (b);
		if(c=="rectangle"){
			int x,y,w,h;
			cin>>x>>y>>w>>h;
			CPoint pos(x,y);
            CRectangle *rec=new CRectangle (pos,x,y);
            button->Setshape(rec);
            vec.push_back(button);
		}
		else{
			int x,y;double r;
			cin>>x>>y>>r;
			CPoint pos(x,y);
            CCircle *cir=new CCircle (pos,r);
            button->Setshape(cir);
            vec.push_back (button);
		}
	}
}
reverse(vec.begin(),vec.end());//
string s;
int x,y;
int sze=vec.size();
while(cin>>s>>x>>y){
	int flag=0;
	CPoint pos(x,y);
	for(int i=0;i<sze;i++){
		if(vec[i]->HitTest(pos)){
			vec[i]->Click();
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<"none hit"<<endl;
	}
}
for(int i=0;i<sze;i++){//需要再把指针指向的对象析构
	delete vec[i];
}
  return 0;
}
