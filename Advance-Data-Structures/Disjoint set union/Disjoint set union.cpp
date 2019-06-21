//Disjoint set union
//Undefined_Error
//Dept. ICE, NSTU-11 Batch
#include<bits/stdc++.h>
using namespace std;
int N = 100; //100 nodes
int p[100]; //initially p[i]=i;
int sz[100];

void init() {
    for (int i=0; i<N; i++) {
        p[i] = i;  //initiallize parrent for every node itself
        sz[i] = 1; //make size of every node 1
    }
}

int find(int x)
{
    if(p[x]==x ) return x;
    p[x]=find(p[x]);
    return p[x]
}

void union(int a,int b)  //merge two node
{
    u = find(a);
    v = find(b);
    if (u==v)  return;  //a & b are already in same set
	
    if (sz[u] > sz[v])  swap(u, v); 
    sz[v] += sz[u]; //merge two node with size
    sz[u] = 0;
    par[u] = v;	// parent of b is in a . find(a) is representative of a
}

int main()
{
	for(int i=0;i<10;i++) p[i]=i;
	
	union(2,5);
	union(5,7);
	
	return 0;
}
