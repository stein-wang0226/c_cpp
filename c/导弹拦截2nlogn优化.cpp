#include <iostream>//nlogn 
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N], d1[N], d2[N], n;
int main() {
	while (cin >> a[++n]);
	n--;		//����
	int len1 = 1, len2 = 1;		//��ʼ����Ϊ1
	d1[1] = a[1];		//�������������г���
	d2[1] = a[1];		//�������������г���
	for (int i=2; i<=n; i++) {		//��a[2]��ʼö��ÿ����(a[1]�Ѿ��ӽ�ȥ��)
		if (d1[len1] >= a[i]) d1[++len1] = a[i];		//�������Ҫ��(������)�ͼ���d1
		else {		//������a[i]�滻d1�е�һ����
			int p1 = upper_bound(d1 + 1, d1 + 1 + len1, a[i], greater<int>()) - d1;
			d1[p1] = a[i];
		}
		if (d2[len2] < a[i]) d2[++len2] = a[i];		//ͬ��
		else {
			int p2 = lower_bound(d2 + 1, d2 + 1 + len2, a[i]) - d2;
			d2[p2] = a[i];
		}
	}
	cout << len1 << endl << len2;		//���
	return 0;		//����
}

