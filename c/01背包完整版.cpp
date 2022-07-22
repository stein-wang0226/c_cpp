#include<iostream>
using namespace std;
#include <algorithm>
 
int w[5] = { 0 , 2 , 3 , 4 , 5 };			//��Ʒ�����2��3��4��5
int v[5] = { 0 , 3 , 4 , 5 , 6 };			//��Ʒ�ļ�ֵ3��4��5��6
int bagV = 8;					        //������С
int dp[5][9] = { { 0 } };			        //��̬�滮��
int item[5];					        //���Ž����
 
void findMax() {					//��̬�滮
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
}
 
void findWhat(int i, int j) {				//���Ž����
	if (i >= 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			item[i] = 0;
			findWhat(i - 1, j);
		}
		else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {
			item[i] = 1;
			findWhat(i - 1, j - w[i]);
		}
	}
}
 
void print() {
	for (int i = 0; i < 5; i++) {			//��̬�滮�����
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)			//���Ž����
		cout << item[i] << ' ';
	cout << dp[4][bagV];
}
 
int main()
{
	findMax();
	findWhat(4, 8);
	print();
 
	return 0;
}

