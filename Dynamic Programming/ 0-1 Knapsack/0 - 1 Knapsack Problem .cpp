//0 - 1 Knapsack Problem 
//Undefined_Error
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define SZ 100005
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sf2int(a,b) scanf("%d%d",&a,&b)
#define sf3int(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
int N[SZ],W[SZ];
int knapscak(int n,int w)
{
	if(n==0||w==0)
	{
		return 0;
	} 
	else if(W[n]>w) return knapscak(n-1,w);
	else
	{
		return max(knapscak(n-1,w),N[n]+knapscak(n-1,w-W[n]));
	}
}

int main()
{
	int t;
	sfint(t);
	forlp1(i,t)
	{
		memset(N,0,sizeof(int));
		memset(W,0,sizeof(int));
		int n,w;
		sf2int(n,w);
		forlp1(j,n) sfint(N[j]);
		forlp1(j,n) sfint(W[j]);
		int result=knapscak(n,w);
		printf("%d\n",result);
	}
	return 0;
}
