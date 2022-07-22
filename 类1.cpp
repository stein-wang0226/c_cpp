#include <bits/stdc++.h>
//#define LOCAL
#define endl "\n"
# pragma GCC optimize(3) 
//#define int long long
using namespace std;
const double pi=3.1415926;
const int N=2e5+5;

int T,n;

class Circle{
  public:
  void cal_len(double R){
      m_len=2*pi*R;
  }
  void cal_s(double R){
    m_S=pi*R*R;
  }
  void show_cost();
  int a;
  private:
  double m_S;
  double m_len;
  double m_cost;
};
void Circle::show_cost(){
  m_cost=m_S*20+m_len*35;
  printf("%.2lf",m_cost);
}
signed main(){
std::ios::sync_with_stdio(false);
cin.tie(0); 
cout.tie(0);
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
Circle a;
double R;
cin>>R;
a.cal_len(R);
a.cal_s(R);
a.show_cost();
    return 0;
}
