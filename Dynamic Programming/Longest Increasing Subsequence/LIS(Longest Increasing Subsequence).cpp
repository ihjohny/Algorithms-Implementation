//LIS(Longest Increasing Subsequence)
//Undefined_Error
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define INF 1<<28
#define ll long long 
#define SZ 100005
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
#define forlpa(i,a,n) for(int i=a;i<=n;i++)
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
int dp[SZ],dir[SZ];
int value[SZ];
int n;
int longest(int u)
{
	if(dp[u]!=-1) return dp[u];
	int maxi=0;
	forlpa(v,u+1,n)
	{
		if(value[v]>value[u])
		{
			if(longest(v)>maxi)
			{
				maxi=longest(v);
				dir[u]=v;
			}
		}
	}
	dp[u]=1+maxi;
	return dp[u];
}
void solution(int start)
{
	while(dir[start]!=-1)
	{
		printf("index %d value %d \n",start,value[start]);
		start=dir[start];
	}
}
int main()
{
	memset(dp,-1,sizeof dp);
	memset(dir,-1,sizeof dir);
	cout<<"the length of secquence "<<endl;
	cin>>n;
	cout<<"enter the elements "<<endl;
	forlp1(i,n)
		cin>>value[i];
	int LIS=0,start;
	forlp1(i,n)
	{
		printf("longest path from : %d\n",longest(i));
		if(longest(i)>LIS)
		{
			LIS=longest(i);
			start=i;
		}
	}	
	printf("LIS = %d Starting point %d \n",LIS,start);
	solution(start);
	cout<<"direction from 7  "<<dir[7]<<endl;
	return 0;
}
