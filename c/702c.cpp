#include<bits/stdc++.h>//������ʱ 
using namespace std;
const int N = 1e4;
long long a[N], x;
bool search_cube( long long k) {
	int pos=( lower_bound(a+1,a+N,k)-a);//��һ�����ڵ��ڵ�λ�� ,�Էֲ���
	if(a[pos]==k)//��ֵΪ����
		return 1;
	return 0;
}
int main() {
	for(int i = 1; i <=N; i ++)//��������������
	a[i] = (long long)i * i * i;//���ã�long long������� 
	int t;
	cin >> t;
	while(t --) {
		bool flag = false;
		cin >> x;
		for(int i = 1; a[i] < x; i ++)
			if(search_cube(x-a[i])) { //���Ҷ�Ӧ�Ĳ�ֵ
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
