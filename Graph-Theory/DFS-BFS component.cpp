//BFS DFS component 
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


int visited[9]={0};
vector<int>list[9];
void dfs(int a);

int main()
{
    int nod,i,j,count=0;
    scanf("%d",&nod);
    for(i=0;i<nod;i++)
    {
        int x;
        cout<<"Node "<<i+1<<endl;
        cout<<"enter its number of vlaue"<<endl;
        scanf("%d",&x);
        cout<<"enter vlaue"<<endl;
        for(j=0;j<x;j++)
        {
            int val;
            scanf("%d",&val);
            list[i].push_back(val);
        }
    }
/*
    for(i=0;i<nod;i++)
    {
        cout<<i+1<<" - ";
        for(j=0;j<list[i].size();j++)
        {
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    for(i=0;i<nod;i++)
    {
        if(visited[i])
        {
           continue;
        }
        else
        {
            count++;
            dfs(i);
        }

    }
    cout<<"compnent is ="<<count<<endl;
    return 0;
}

void dfs(int a)
{
    if(visited[a]) return ;
    visited[a]=1;

    for(int i=0;i<list[a].size();i++)
    {
        dfs(list[a][i]);
    }
}
