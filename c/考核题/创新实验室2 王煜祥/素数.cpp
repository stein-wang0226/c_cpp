#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int n,cnt=1;
	cin>>n;int i=3;
while(i<=n){
	
	
		int j=2;//�������ⲿʹ�� ,����i=2����� 
		for( j=2; j<=int(sqrt(i)); j++) {
			if (i%j==0) {
				break;
			}
		}
		if (j>sqrt(i))cnt++;
	i+=2;
	}

	cout<<cnt;





	return 0;
}
