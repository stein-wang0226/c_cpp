#include <bits/stdc++.h>
//# pragma GCC optimize(3)
#define endl "\n"
using namespace std;

class CUIControl{
    protected:
        string m_name;
    public :
        virtual void Click()const;
        CUIControl(){
            m_name="";   //默认构造
        }; //构造
        CUIControl(string name):m_name(name){}; //构造
};

void CUIControl::Click()const{
    cout<<m_name<<" "<<"Clicked"<<endl;
}   
class CMenu: public CUIControl{
    public:
        CMenu(string name):CUIControl(name){};
    void Click ()const;
};
void CMenu::Click()const{
    cout<<"menu-"<<m_name<<"Clicked"<<endl;
}


class CButton: public CUIControl{
    public:
    CButton(string name):CUIControl(name){};
    void Click ()const;
};
void CButton::Click()const{
    cout<<"button-"<<m_name<<"Clicked"<<endl;
}
int main() {
int  n;
cin>>n;
string a,b;
// 这样输入处理也太麻烦了  所以我就直接用map了   没必要
map<int,pair<string,string>>mp;
int cnt1=0,cnt2=0;
for(int i=1;i<=n;i++){
    cin>>a>>b;
    mp[i]={a,b};
}

string s;
while(cin>>s){
    int id;
    cin>>id;
    if(mp[id].first=="menu"){
            cout<<"menu-"<< mp[id].second<<" "<<"Clicked"<<endl;
    }
    else {

                    cout<<"button-"<< mp[id].second<<" "<<"Clicked"<<endl;
    }
}
// CUIControl a("123");
// CButton b("456");
// CMenu c("156");
// a.Click();
// b.Click();
// c.Click();

  return 0;
}
