
//递归dfs溢出
// #include <bits/stdc++.h>
// using namespace std;
// int t,n, a,b,flag;
// void dfs(int n){
//     if(n==1){
//       flag = 1;
//       return;
//     }
//     if (!(n % a)) dfs(n / a);  //先除后减
//     if (n - b > 0) dfs(n - b);
// }
// int main() {
//   cin >> t;
//   while (t--) {
//     cin >>n >> a>>b;
//     flag=0;
//     dfs(n);
//     if(flag)cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
//     }
//   return 0;
// }

//思维：二叉树扩展（左*a，右+b）   每个有效元素都满足： n==a^k+tb    (k,b位任意int)
//n==1   特判
#include <bits/stdc++.h>
using namespace std;
int t,n, a,b,flag;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >>n >> a>>b;
    int flag=0;
    if(a==1){//特判
        if((n-1)%b==0)flag=1;//n%b==1错   ：n=1,b=1的情况
    } else {
      for (long long i = 1; i <= n ; i *= a) {
        if (n % b == i % b) {
          flag = 1;
          break;
        }
      }
    }
      if(flag)cout<<"Yes"<<"\n";
      else cout<<"No"<<"\n";
   
  }
 // system("pause");
 
    }