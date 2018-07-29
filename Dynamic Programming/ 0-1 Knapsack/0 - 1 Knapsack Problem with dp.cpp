//0 - 1 Knapsack Problem with dp
//Undefined_Error
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define SZ 100005
#define MX 100000000
#define sfint(a) scanf("%d",&a)
#define sfint2(a,b) scanf("%d%d",&a,&b)
#define sfint3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define forlp0(i,n) for(int i=0;i<n;i++)
#define forlp1(i,n) for(int i=1;i<=n;i++)
int N[SZ],W[SZ];
int dp[1000][1000];

//recursive
/*
int knapsack(int n,int w)
{
	if(n==0||w==0)
	{
		dp[n][w]=0;
		return 0;
	}
	if(dp[n][w]!=-1) return dp[n][w]; 
	if(W[n]>w)
	{
		dp[n][w]=knapsack(n-1,w);
		return dp[n][w];
	}
	else
	{
		dp[n][w]=max(knapsack(n-1,w),N[n]+knapsack(n-1,w-W[n]));
		return dp[n][w];
	}
}
*/ 

//iterative
int knapsack(int n,int w)
{
	//construting dp table
   for (int i=0; i<=n;i++)
   {
       for (int j=0;j<= w;j++)
       {
           if (i==0 || j==0)
               dp[i][j]=0;
           else if (W[i] <= j)
                 dp[i][j] = max(N[i]+ dp[i-1][j-W[i]],  dp[i-1][j]);
           else
                 dp[i][j]= dp[i-1][j];
       }
   }
   return dp[n][w];
}

//selected items
void pick(int n,int w)
{
	if(n==0 || w==0) return ;
	if(dp[n][w]!=dp[n-1][w])
	{
		cout<<n<<"  ";
		pick(n-1,w-W[n]);
	}
	else
	{
		pick(n-1,w);
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
		memset(dp,-1,sizeof(dp));
			
		int n,w;
		sfint2(n,w);
		forlp1(j,n) sfint2(N[j],W[j]); //item value and weight
		int result=knapsack(n,w);
		printf("%d\n",result);
		printf("Seletcted item list :");
		pick(n,w);
		
	}
	return 0;
}
