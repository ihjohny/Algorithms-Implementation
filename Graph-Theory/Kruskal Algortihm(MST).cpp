//kruskal's algorithm
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge
{
	int u,v,w;
};
bool operator <(Edge a,Edge b)
{
	return a.w < b.w;
}
vector<Edge> E;
int p[10000];
int find(int x)
{
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}

int kruskal()
{
	for(int i=0;i<1000;i++)
	{
		p[i]=i;
	}
	sort(E.begin(),E.end());
	int ans=0;
	int size=E.size();
	for(int i=0;i<size;i++)
	{
		if(find(E[i].u)!=find(E[i].v))
		{
			p[find(E[i].u)]=find(E[i].v);
			ans=ans+E[i].w;
		}
	}
	cout<<"ans =  "<<ans;
	return ans;
}
int main()
{
	while(1)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(u==0&&v==0)
			break;
			
		Edge test;
		test.u=u;
		test.v=v;
		test.w=w;
		E.push_back(test);
		test.u=v;
		test.v=u;
		test.w=w;
		E.push_back(test);
	}	
	kruskal();
	return 0;
}