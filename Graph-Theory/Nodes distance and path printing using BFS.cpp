//two node distance and path printing
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

    vector<int>list[15];
    int visited[15]={0};
    int dist[15]={0};
    int address[15]={0};
    vector<int>path;

    void bfs(int s,int t,int n)
    {
        queue<int>q;
        visited[s]=1;
        dist[s]=0;
        address[s]=s;
        q.push(s);

        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<list[x].size();i++)
            {
                if(visited[list[x][i]]==0)
                {
                    visited[list[x][i]]=1;
                    dist[list[x][i]]=dist[x]+1;
                    address[list[x][i]]=x;
                    q.push(list[x][i]);
                }
            }
        }
        if(visited[t]==0)
        {
            cout<<"no path between s and t"<<endl;
            return;
        }
        int now=address[t];
        path.push_back(t);
        while(now!=s)
        {
            now=address[now];
            path.push_back(now);
        }
        reverse(path.begin(),path.end());
        cout<<" distance = "<<dist[t]<<endl;
        cout<<" path = "<<endl;
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<"  ";
        }
    }
int main()
{
    int x,i,j;
	int s,t,n;
	cin>>s>>t>>n; // s starting point , n total node
	while(1)
	{
		cin>>i>>j;
		if(i==0&&j==0)
		break;
		list[i].push_back(j);
	}
	bfs(s,t,n);

    return 0;
}