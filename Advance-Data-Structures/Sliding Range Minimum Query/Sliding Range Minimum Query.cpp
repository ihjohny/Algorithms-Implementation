//Sliding Range Minimum Query
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
int arra[SZ];
int result[SZ];
int n;
void sliding_rmq(int m)
{
	int t=0;
	deque<pair<int,int> >p;
	for(int i=0;i<n;i++)
	{
		while(!p.empty() && p.front().first>=arra[i])
		{
			p.pop_front();
		}
		p.push_front(make_pair(arra[i],i));
		while(!p.empty() && p.back().second<=i-m)
		{
			p.pop_back();
		}
		if(i>=m-1)
		{
			result[t++]=p.back().first;
		}
	}
	
}

int main()
{
	memset(arra,0,sizeof arra);
	memset(result,0,sizeof result);
	n=0;
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&arra[i]);
	
	sliding_rmq(m);
	
	printf("Result : ");
	for(int i=0;i<=m;i++)
	{
		printf("%d  ",result[i]);
	}
	return 0;
}
