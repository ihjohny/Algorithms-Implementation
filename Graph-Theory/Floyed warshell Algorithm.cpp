///floyed warshell algorithm (all pair shortest path)
#include<bits/stdc++.h>
using namespace std;
#define INF 100000000

int main()
{
	int matrix[100][100];
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			matrix[i][j]=INF;
		}
	}
	while(1)
	{
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		if(u==0&&v==0)
			break;
		matrix[u][v]=cost;
	}
	///floyed warshell algorithm
	int next[1000][1000];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			next[i][j]=j;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(matrix[i][j]>matrix[i][k]+matrix[k][j])
				{
					matrix[i][j]=matrix[i][k]+matrix[k][j];
					next[i][j]=next[i][k];
				}
			}
		}
	}
		
	//find_path(int i,int j)
	int source,dest;
	vector<int>path;
	path.push_back(source);
	while(source!=dest)
	{
		source=next[source][dest];
		path.push_back(source);
	}
		
	return 0;
}