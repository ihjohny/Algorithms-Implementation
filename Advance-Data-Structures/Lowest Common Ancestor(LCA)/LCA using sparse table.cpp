//LCA using sparse table
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
#define MX 100000000
int parent[SZ];
int level[SZ];
int sp_table[SZ][22];
vector<int>tree[100];

void dfs(int from,int u, int lev)
{
	level[u]=lev;
	parent[u]=from;
	for(int i=0;i<(int)tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v==from) continue;
		dfs(u,v,lev+1);
	}
}
 
int lca_query(int N,int p, int q)
{
	int temp,log;
	if(level[p]<level[q])
	{
		temp=p;
		p=q;
		q=temp;
	}
	log=1;
	while(1)
	{
		int next=log+1;
		if((1<<next) > level[p]) break;
		log++;
	}
	
	for(int i=log;i>=0;i--)
	{
		if(level[p]-(1<<i)>=level[q])
				p=sp_table[p][i];
	}
	if(p==q)
		return p;
	for(int i=log;i>=0;i--)
	{
		if( sp_table[p][i]!=-1 && sp_table[p][i] != sp_table[q][i])
			p=sp_table[p][i],q=sp_table[q][i];
	}
	return parent[p];
}

void lca_init(int N)
{
	memset(sp_table,-1,sizeof sp_table);
	for(int i=0;i<N;i++)
	{
		sp_table[i][0]=parent[i];
	}
	for(int j=1;(1<<j)<N;j++)
	{
		for(int i=0;i<N;i++)
		{
			if(sp_table[i][j-1]!=-1)
				sp_table[i][j]=sp_table[sp_table[i][j-1]][j-1];
		}
	}
}

int main()
{
	tree[1].push_back(2);
	tree[2].push_back(4);
	tree[2].push_back(5);
	tree[1].push_back(3);
	tree[3].push_back(6);
	
	dfs(1,1,0);
	lca_init(6);
	
	printf("%d\n",lca_query(6,6,6));
	
	return 0;
}
