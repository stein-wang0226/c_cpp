#include<iostream>
#include<cstdio>
using namespace std;
int n,ans1,ans2[10001][11],sum,a[11];
void trys(int t,int m)//t����ǰ�ĳ��Եĵ��ϡ�m����ǰ��ζ�̶�
{
    if (t>10) 
    {
        if (m==n) //�����ζ�̶��������Ҫ����� 
        {
            ans1++;//ͳ�Ʒ������� 
            for (int i=1;i<=10;i++)
            ans2[ans1][i]=a[i];//����𰸵����� 
        }
        return ;
    }
    for (int i=1;i<=3;i++)
    {
        if (m+i>n) break;//���������Ҫ����ô����ľͿ���ֱ�Ӻ��� 
        a[t]=i;//����� 
        trys(t+1,m+i);//�鿴��һ�ֵ��� 
        a[t]=0;//״̬�ָ� 
    }
}
int main()
{
    cin>>n;
    trys(1,0);//�ӵ�һ�ֵ��Ͽ�ʼ���ԣ���ζ�̶�Ϊ0 
    cout<<ans1<<endl;
    for (int i=1;i<=ans1;i++)
    {
        for (int j=1;j<=10;j++)
            cout<<ans2[i][j]<<" ";
        cout<<endl;
    }//������ 
    return 0;
} 

