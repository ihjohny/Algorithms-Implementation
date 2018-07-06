//topological sort algorithm
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	vector<int>graph[1001];
	int indegree[1001]={0};
	int topsort[1001]={0};
	int node,edge;
	while(scanf("%d%d",&node,&edge))
	{
		
	for(int i=1;i<=edge;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		indegree[v]=indegree[v]+1;
	}
	//for(int i=1;i<=node;i++)
	//{
	//	cout<<indegree[i]<<" ";
	//}
	
	queue<int>pq;
	for(int i=1;i<=node;i++)
	{
		if(indegree[i]==0){
			
			 pq.push(i);
		 }
	}
	int t=0;
	while(!pq.empty())
	{
		int top=pq.front();
		pq.pop();
		topsort[t++]=top;
		int size=graph[top].size();
		for(int i=0;i<size;i++)
		{
			int connected_element=graph[top][i];
			indegree[connected_element]--;
			
			if(indegree[connected_element]==0)
		 		pq.push(connected_element);
		}
	}
//	cout<<"sorted array "<<endl;
	for(int i=0;i<node;i++)
		cout<<topsort[i]<<"  ";
		
	cout<<endl;
	}

	return 0;
}
