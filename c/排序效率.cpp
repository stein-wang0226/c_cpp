#include <bits/stdc++.h>

#include <ctime>
//# pragma GCC optimize(3)
//#define int long long
#define endl "\n"
using namespace std;

const int N = 100;

const int maxn = 1e8 + 5;
int T, n, a[maxn], temp[maxn];

void quick_sort(int l, int r) {
  if (l >= r) return;
  int i = l - 1, j = r + 1, x = a[l + r >> 1];  //分界点
  while (i < j) {
    do i++;
    while (a[i] < x);  //一直移动到需要改变
    do j--;
    while (a[j] > x);
    if (i < j) swap(a[i], a[j]);
  }
  quick_sort(l, j);
  quick_sort(j + 1, r);
}
void merge_sort(int l, int r) {
  if (l >= r) return;
  int mid = l + r >> 1;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);  // 递归到单个

  int k = 1, i = l, j = mid + 1;  //同时从开头比较
  while (i <= mid && j <= r) {    //直到一方清空
    if (a[i] <= a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while (i <= mid) temp[k++] = a[i++];  //可能一方还有剩余
  while (j <= r) temp[k++] = a[j++];

  for (int i = l, j = 1; i <= r; i++, j++) a[i] = temp[j];  // 重新赋值注意下标
}
void bubble() {
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= n - i; j++) {
      if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }
  }
}
void change() {
  for (int i = 1; i <= n - 1; i++) {
    int k = i;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[k]) k = j;
    }
    swap(a[i], a[k]);
  }
}

void Insert()
{
	for (int j=2; j<=n; j++)
	{
		int temp = a[j];
		int i = j-1;
		while (i>=1 && a[i]>temp)
		{
			a[i+1] = a[i];// 后移
			i--;    // 向前比
		}
		a[i+1] = temp;
	}
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    a[i] = rand() % 100000;
  }
  clock_t c1 = clock();
  // sort(a+1,a+1+n);
//bubble();
  //Insert();
  cout << "Time Used:" << clock() - c1 << "ms" << endl;

  return 0;
}