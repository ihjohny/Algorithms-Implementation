#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>adjlist[100];
int visited[100];

void bfs(int s,int n)// s starting point , n total node 
{
	cout<<"BFS :"<<endl;
	
	queue<int>q;
	q.push(s);
	visited[s]=1;
	cout<<s<<" ";
	int u;
	
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<adjlist[u].size();i++)
		{
			if(visited[adjlist[u][i]]==0)
			{
				q.push(adjlist[u][i]);
				visited[adjlist[u][i]]=1;
				cout<<adjlist[u][i]<<" ";//print list
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
	bfs(s,n);
	
	return 0;
}