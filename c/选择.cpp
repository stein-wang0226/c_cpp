#include <bits/stdc++.h>
#include <ctime>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 100;

const int maxn=1e5+5;
int T, n, a[maxn];
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin>>n;

 for(int i=1;i<=n;i++){
   a[i]=rand()%1000000;
 }
 clock_t c1 = clock();
for(int i=1;i<=n-1;i++){
  int k=i;
  for(int j=i+1;j<=n;j++){
    if(a[j]<a[k])k=j;
  }
  swap(a[i],a[k]);
}
 cerr << "Time Used:" << clock() - c1 << "ms" << endl;
  return 0;
}
