#include<iostream>
using namespace std;
#include <algorithm>
 
int main()
{
	int w[5] = { 0 , 2 , 3 , 4 , 5 };			//��Ʒ�����2��3��4��5
	int v[5] = { 0 , 3 , 4 , 5 , 6 };			//��Ʒ�ļ�ֵ3��4��5��6
	int bagV = 8;					        //������С
	int dp[5][9] = { { 0 } };			        //��̬�滮��
 
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= bagV; j++) {
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
 
	//��̬�滮������
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
 
	return 0;
}
