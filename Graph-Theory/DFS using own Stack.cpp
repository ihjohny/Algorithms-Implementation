#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int>adjlist[100];
int edge_id[100];
int visited[100];

void dfs(int s,int n)
{
	for(int i=0;i<n;i++) edge_id[i]=visited[i]=0;
	
	stack<int>S;
	S.push(s);
	
	while(!S.empty())
	{
		int u=S.top();
		S.pop();
		
		while(edge_id[u]<adjlist[u].size())
		{
			int v=adjlist[u][edge_id[u]];
			edge_id[u]++;
			if(visited[u]==0)
			{
				visited[u]=1;
				S.push(u);
				S.push(v);
				break;
			}
		}
	}
}

int main()
{
	int x,i,j;	
	int s,n;
	cin>>s>>n; // s starting point , n total node 
	while(1)
	{
		cin>>i>>j;
		if(i==0&&j==0)
		break;
		adjlist[i].push_back(j);
	}
	dfs(s,n);
	
	return 0;
}