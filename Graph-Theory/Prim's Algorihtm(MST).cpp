//minmum spaning tree (prims algorithm)
#include<iostream>
#include<queue>
#include<vector>
#define INF 1000000
using namespace std;
typedef pair<int,int> PII;
vector<PII>list[100];
struct node
{
	int u;
	int cost;
	node(int _u,int _cost)
	{
		u=_u;
		cost=_cost;
	}
};

bool operator<(node A,node B)
{
	return A.cost>B.cost;
}

priority_queue<node>pq;
int visited[1000];
int cost[1000];

int prim(int start,int n){
	for(int i=0;i<=n;i++)
	{ 
		cost[i]=INF; visited[i]=0;
	}
	int ans=0;
	cost[start]=0;
	pq.push(node(start,0));
	while(!pq.empty())
	{
		node top=pq.top();
		pq.pop();
		if(visited[top.u])
			continue;
			
		visited[top.u]=1;
		//cout<<"top.u  "<<top.u<<endl;
		//cout<<"top.cost  "<<top.cost<<endl;
		ans=ans+top.cost;
		int size=list[top.u].size();
		for(int i=0;i<size;i++)
		{
			PII N = list[top.u][i];
			if(visited[N.first])
				continue;
			if(N.second<cost[N.first])
			{
				cost[N.first]=N.second;
				pq.push(node(N.first,N.second));
			}
		}
	}
	return ans;
}

int main()
{
	int i,j,cost;	
	int s,n;
	cin>>s>>n; // s starting point , n total node 
	while(1)
	{
		cin>>i>>j;
		if(i==0&&j==0)
		break;
		
		cin>>cost;
		PII in1,in2;
		
		in1.first=j;
		in1.second=cost;
		list[i].push_back(in1);
		
		in2.first=i;
		in2.second=cost;
		list[j].push_back(in2);
		
	}
	
	int result;
	result=prim(s,n);
	cout<<"result ="<<result<<endl;
	return 0;
}