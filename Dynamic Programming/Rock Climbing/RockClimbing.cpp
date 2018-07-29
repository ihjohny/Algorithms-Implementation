//Rock Climbing
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
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
int mat[][10]={
	{-1,2,5},
	{4,-2,3},
	{1,2,10}
};
int dp[100][100];
int r=3,c=3;
int RockClimbing(int i,int j)
{
	if(i>=0 && i<r && j>=0 && j<c)
	{
		if(dp[i][j]!=-1) return dp[i][j];
		int ret=-INF;
		ret=max(ret,RockClimbing(i+1,j)+mat[i][j]);
		ret=max(ret,RockClimbing(i+1,j-1)+mat[i][j]);
		ret=max(ret,RockClimbing(i+1,j+1)+mat[i][j]);
		return dp[i][j]=ret;
	}
	else 
		return 0;
}
int main()
{
	memset(dp,-1,sizeof dp);
	printf("%d\n",RockClimbing(0,0)); //initial pointing 0,0
	return 0;
}
