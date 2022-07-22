#include<iostream>
#include <map>
using namespace std;
long long n, a[400005], x, maxa = 0, ans = 0, t, cnt[400005];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%lld", &n);//ÊäÈën¸öÊı
		ans = 0;
		for (int i = 1; i <= n; i ++ ) 	scanf("%lld", &a[i]);
		for (int i = 0; i <= 2 * n; i ++ ) cnt[i] = 0;

		for (int i = 1; i <= n; i ++ )
			cnt[a[i] - i + n] ++ ;
		for (int i = 0; i <= 2 * n; i ++ )
			ans += cnt[i] * (cnt[i] - 1) / 2;
		printf("%lld\n", ans);
	}

	return 0;
}
