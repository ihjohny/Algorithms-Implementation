//Coin Changing
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
#define rvforlp(i,n) for(int i=n-1;i>=0;i--)
int coin[SZ];
int dp[1000][1000];
int totalCoin;
int make;
int call(int i,int amount)
{
	if(i>=totalCoin+1)
	{
		if(amount==0) return 1;  //All coins have been taken
		else return 0;
	}
	if(dp[i][amount]!=-1) return dp[i][amount];
	int ret1=0,ret2=0;
	if(amount-coin[i]>=0)
		ret1=call(i,amount-coin[i]); //try to take coin i ,if we do i+1 then one coin can take only one time
	ret2=call(i+1,amount); //don't take coin i
	
	return dp[i][amount]=ret1|ret2;
	
}

int main()
{
	cout<<"Enter the number of coin"<<endl;
	cin>>totalCoin;
	forlp1(i,totalCoin)
	{
		cin>>coin[i];
	}
	memset(dp,-1,sizeof dp);
	while(1)
	{
	cin>>make;
	if(make==0) break;
	if(call(1,make))
		cout<<"This is possible"<<endl;
	else 
		cout<<"This is not possible"<<endl;
	}
	return 0;
}
