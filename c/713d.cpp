////������,�����ֿ���,һ���������������ֺ�,������
//����Ҫ��ǰn+1��������ӵõ��ͼ�ȥ��������,�õ�x,�����
//���ִ������x����������,���򿴵ڶ������,�ڶ���������Ǻ�,
//����������x,�������ֻ��Ҫ��ǰn��������ӿ��Ƿ���ڵ�n+1�����ּ�
//��,������������������,�����-1
#include <bits/stdc++.h>
using namespace std;
long long b[200005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		map<long long ,int >q;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n+2;i++)
		{
			scanf("%lld",&b[i]);
			q[b[i]]++;
		}
		sort(b+1,b+1+2+n);
		long long sum=0;
		for(int i=1;i<=n+1;i++)
		{
			sum+=b[i];
		}
		long long c=sum-b[n+2];
		q[b[n+2]]--;
		if(q[c])
		{
			q[c]--;
			for(auto x:q)
			{
				for(int i=0;i<x.second;i++)
				{
					cout<<x.first<<" ";
				}
			}
			cout<<endl;
		} 
		else 
		{
			long long s=0;
			for(int i=1;i<=n;i++)
			{
				s+=b[i];
			}
			if(b[n+1]==s)
			{
				for(int i=1;i<=n;i++)
				{
					cout<<b[i]<<" ";
				}
				cout<<endl;
			}
			else cout<<-1<<endl;
		}
	}
	return 0;
}
