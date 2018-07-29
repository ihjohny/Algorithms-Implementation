//LCS all Solution Print
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 1005
#define MX 10000000
char A[SZ],B[SZ];
int lenA,lenB;
int dp[SZ][SZ];
bool visited[SZ][SZ];
string ans;

int calcLCS(int i,int j)
{
	if(A[i]=='\0'||B[j]=='\0') 
		return 0;
	if(visited[i][j]) 
		return dp[i][j];
	
	int ans=0;
	if(A[i]==B[j]) 
		ans=1+calcLCS(i+1,j+1);
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	visited[i][j]=true;
	dp[i][j]=ans;
	return dp[i][j];
}

void printallLCS(int i,int j)
{
	if(A[i]=='\0' || B[j]=='\0')
	{
		cout<<ans<<endl;
		return ;
	}
	if(A[i]==B[j])
	{
		ans+=A[i];
		printallLCS(i+1,j+1);
		ans.erase(ans.end()-1);
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1])
			printallLCS(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1])
			printallLCS(i,j+1);
		else
		{
			printallLCS(i+1,j);
			printallLCS(i,j+1);
		}	
	}
}
int main()
{
	scanf("%s%s",A,B);
	lenA=strlen(A);
	lenB=strlen(B);
	printf("Length of the LCS : %d\n",calcLCS(0,0));
	printallLCS(0,0);
	return 0;
}
