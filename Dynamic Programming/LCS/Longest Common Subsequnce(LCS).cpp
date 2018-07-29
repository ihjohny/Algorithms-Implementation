//Longes Common Subsequence(LCS)
#include<iostream>
#include<cstring> //for strlen function
using namespace std;
#define SZ 100
int L[SZ][SZ];
char str1[SZ];
char str2[SZ];

int LCS(int n,int m)
{
	for(int i=0;i<=n;i++)
	{
		L[i][0]=0;
	}
	for(int j=0;j<=m;j++)
	{
		L[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(str1[i]==str2[j])
			{
				L[i][j]=L[i-1][j-1]+1;
			}
			else
			{
				L[i][j]=max(L[i][j-1],L[i-1][j]);
			}
		}
	}
	return L[n][m];
}

int main()
{
	cout<<"Enter two string "<<endl;
	cin>>str1;
	cin>>str2;
	
	int len1=strlen(str1);
	int len2=strlen(str2);
	int result=LCS(len1,len2);
	
	cout<<"Length of Longest Commons Subsequnce "<<result<<endl;
	
	return 0;
}
