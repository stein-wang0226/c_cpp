#include<bits/stdc++.h>//暴力超时 
using namespace std;
const int N = 1e4;
long long a[N], x;
bool search_cube( long long k) {
	int pos=( lower_bound(a+1,a+N,k)-a);//第一个大于等于的位置 ,对分查找
	if(a[pos]==k)//差值为立方
		return 1;
	return 0;
}
int main() {
	for(int i = 1; i <=N; i ++)//储存所有立方数
	a[i] = (long long)i * i * i;//不用（long long）会溢出 
	int t;
	cin >> t;
	while(t --) {
		bool flag = false;
		cin >> x;
		for(int i = 1; a[i] < x; i ++)
			if(search_cube(x-a[i])) { //查找对应的差值
				flag = 1;
				break;
			}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
