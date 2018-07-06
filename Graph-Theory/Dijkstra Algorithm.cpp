///Dijkstra algorithm implement
#include<iostream>
#include<queue>
#include<vector>
#define inf 100000000
using namespace std;
typedef pair <int,int> pii;
struct node
{
    int u,cost;
    node(int at,int _cost)
    {
        u=at;
        cost=_cost;
    }
};
bool operator <(node A,node B)
{
    return A.cost>B.cost;
}
vector<pii>list[1000];
priority_queue<node>pq;
int dist[100];
void dijkstra(int s,int n)
{
    for(int i=0;i<=n;i++) dist[i]=inf;
    dist[s]=0;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        node test=pq.top();
        //cout<<"test.u"<<test.u<<endl;
        pq.pop();
        if(test.cost>dist[test.u])continue;

        int size=list[test.u].size();
        for(int i=0;i<size;i++)
        {
            pii tt=list[test.u][i];

            if(dist[tt.first]>tt.second+test.cost)
            {
                dist[tt.first]=tt.second+test.cost;
                pq.push(node(tt.first,dist[tt.first]));
            }
        }
    }
}
int main()
{
	int i,j,cost;
	int s,n;
	cin>>s>>n; // s starting point , n total node
	for(int g=0;g<n;g++)
	{
		cin>>i>>j>>cost;
		pii in1,in2;

		in1.first=j;
		in1.second=cost;
		list[i].push_back(in1);

		in2.first=i;
		in2.second=cost;
		list[j].push_back(in2);

	}
	int result;
	dijkstra(s,n);
	for(int i=0;i<n;i++)
	cout<<"dist "<<i<<"  "<<dist[i]<<endl;
	return 0;
}