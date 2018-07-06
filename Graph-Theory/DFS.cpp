//recursive method
#include<iostream>
#include<vector>
using namespace std;

vector<int>adjlist[100];
int visited[100];

void dfs(int at)
{
	if(visited[at]==1) 
	{
		return;
	}
	visited[at]=1;
	cout<<at<<" ";
	
	for(int i=0;i<adjlist[at].size();i++)
	{
		dfs(adjlist[at][i]);
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
	cout<<"DFS :"<<endl;
	dfs(s);
	return 0;
}