#include<bits/stdc++.h>
#include<windows.h>
//����һ��������������exe�����������������ɵ����ݷ���data.txt�У�����뱩���ֱ�������ݣ������бȽϣ�����ͬ����ֱ����������ʱtδ����0��������жϳ�������Ϊ��fc���������Ὣ��������������ӡ������ 
using namespace std;
int main(){
	int t=500;
	while(t--){//һֱѭ�� 
		system("code3.exe>data.in");//�����ݵ�exe,����data.in 
		system("��������1.exe<data.in>1.out");//����1�� 
		system("��������2.exe<data.in>2.out");//����2��
		if(system("fc 1.out 2.out")){//fc�ǱȽ�ָ��
			printf("error!!\n");
			system("pause");
		}
	}
	return 0;
}

