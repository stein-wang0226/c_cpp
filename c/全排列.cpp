#include <stdio.h>
#include <string.h>

int v[1005], a[1005], n;//v���
void dfs(int c) {
	if (c == n) {
		for (int i = 0; i < n; i++)
			printf("%d", a[i]);
		printf("\n");
	} else {
		for (int i = 1; i <= n; i++) {//ʹai ������i��n
			if (!v[i]) {//��δ��ǵĽ��д��� ���ӵ�һ��δ��ǵ�i���룬ǰi-1���ѱ�Ǵ�С����
				v[i] = 1;
				a[c] = i;//�ҵ���һ��δ��ǵĽ�i����
				dfs(c + 1);
				v[i] = 0;//��ԭ���� ,(��һ��dfs��3����i=4�� v4=0����һ��ѭ��ʹa��3��=5���±���㿪ʼ��
			}//���ݲ�������һѭ��������ʵ��ȫ����
		}
	}
}
int main() {
	while (scanf("%d",&n) != EOF) {
		memset(v, 0, sizeof(v));
		memset(a, 0, sizeof(a));
		dfs(0);
	}
	return 0;
}

