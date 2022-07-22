////先排序,有两种可能,一是最大的数字是数字和,这种情
//况需要将前n+1个数字相加得到和减去最大的数字,得到x,如果序
//列种存在这个x则该情况成立,否则看第二种情况,第二大的数字是和,
//最大的数字是x,这种情况只需要将前n个数字相加看是否等于第n+1个数字即
//可,如果两种情况都不满足,则输出-1
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
