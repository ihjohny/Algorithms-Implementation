///dfs using starting time and finishing time
///toplogical sort
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1000];
int color[1000]={0};///0 =white 1=grey 2=black
int tclock=0;
int start_time[1000],finish_time[1000];

void dfs(int source)
{
	tclock=tclock+1;
	start_time[source]=tclock;
	color[source]=1;
	for(int i=0;i<graph[source].size();i++)
	{
		if(color[graph[source][i]]==0)
		{
			dfs(graph[source][i]);
		}
	}
	color[source]=2;
	tclock=tclock+1;
	finish_time[source]=tclock;
	return ;
}

int main()
{
	int node,edge;
	while(scanf("%d%d",&node,&edge)==2)
	{
		if(node==0 && edge==0)
			break;
		for(int i=1;i<=edge;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			graph[u].push_back(v);
			//graph[v].push_back(u);
		}
		dfs(1);
	}
	return 0;
}