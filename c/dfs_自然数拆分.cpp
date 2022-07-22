//当找到第一个1时，其右下必然是圈内的0，那么只要从这个0开始广搜寻找**
#include <bits/stdc++.h>
#define LOCAL
using namespace std;
int a[35][35], n;
struct node {
  int x, y;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(node start) {
  queue<node> que;
  que.push(start);
  while (!que.empty()) {
    node u = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      node cur;
      cur.x = u.x + dx[i];
      cur.y = u.y + dy[i];
      if (a[cur.x][cur.y] == 0) {
        a[cur.x][cur.y] = 1;
        que.push(cur);
      }
    }
  }
}
int main() {
    #ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
  cin >> n;
  node start;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; i <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; i <= n; j++) {
      if (a[i][j] == 1) {
        start.x = i + 1;
        start.y = j + 1;
        break;
      }
    }
  }

  bfs(start);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }

  return 0;
}
