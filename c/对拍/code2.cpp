#include<bits/stdc++.h>
#include<windows.h>
//运行一遍另外三个程序exe，将数据生成器生成的数据放在data.txt中，标程与暴力分别读入数据，并进行比较，若不同，则直接跳出，此时t未减到0，故最后判断出错误，因为“fc”函数，会将两个程序的输出打印出来。
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int ans=a+b+c;
	cout<<ans;
	return 0;
}

