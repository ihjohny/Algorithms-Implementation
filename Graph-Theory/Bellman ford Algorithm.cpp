///bellman ford algorithm
#include<iostream>
#include<vector>
#define inf 100000000
using namespace std;
struct edge
{
	int u,v,w;
};
vector<edge>E;
int dist[10000];

void bellmanford(int source,int n)
{
	for(int i=0;i<n;i++)
	{
		dist[i]=inf;
	}
	dist[source]=0;
	int size=E.size();
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(dist[E[j].v]>dist[E[j].u]+E[j].w)
			{
				dist[E[j].v]=dist[E[j].u]+E[j].w;
			}
		}
	}
}
int main()
{
	int s,n,u,v,w,d;
	cin>>s>>d>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		edge test;
		test.u=u;
		test.v=v;
		test.w=w;
		E.push_back(test);
	}
	bellmanford(s,n);
	
	cout<<dist[d];
	
	return 0;
}