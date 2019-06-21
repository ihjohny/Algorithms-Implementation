//Segment Tree -2(Lazy Propagation)
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SZ 100005
int arra[SZ];
struct info
{
	int sum;
	int prop;
}tree[SZ*3];
void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].sum=arra[b];
		return;
	}
	int mid=(b+e)/2;
	int left=node<<1;
	int right=(node<<1)+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node, int b, int e, int i,int j, int value)
{
	if(b>j || e<i)
		return;
	if(b>=i && e<=j)
	{
		tree[node].sum=tree[node].sum+(e-b+1)*value;
		tree[node].prop=tree[node].prop+value;
		return;
	}
	int mid=(b+e)/2;
	int left=node<<1;
	int right=(node<<1)+1;
	update(left,b,mid,i,j,value);
	update(right,mid+1,e,i,j,value);
	tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e, int i,int j,int carry=0)
{
	if(b>j || e<i)
		return 0;
	if(b>=i && e<=j)
		return tree[node].sum+(e-b+1)*carry;
	int mid=(b+e)/2;
	int left=node<<1;
	int right=(node<<1)+1;
	int p1=query(left,b,mid,i,j,carry+tree[node].prop);
	int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
	return p1+p2;
}
int main()
{
	int x;
	cout<<"Enter the Number of array elements "<<endl;
	scanf("%d",&x);
	memset(arra,0,sizeof arra);
	memset(tree,0,sizeof tree);
	cout<<"Enter "<<x<<" elememts"<<endl;
	for(int i=1;i<=x;i++)
	{
		scanf("%d",&arra[i]);
	}
	init(1,1,x);
	
	cout<<"Enter number of time operation"<<endl;
	int operation;
	scanf("%d",&operation);
	for(int k=0;k<operation;k++)
	{
			cout<<"Enter 1 for qurery operation"<<endl;
			cout<<"Enter 2 for update operation"<<endl;
			int op;
			scanf("%d",&op);
			if(op==1)
			{
				cout<<"Enter indexs for query opertaion"<<endl;
				int i,j;
				scanf("%d%d",&i,&j);
				cout<<"Query result = "<<query(1,1,x,i,j)<<endl;
			}
			else if(op==2)
			{
				cout<<"Enter index and value for update opertaion"<<endl;
				int i,j,value;
				scanf("%d%d%d",&i,&j,&value);
				update(1,1,x,i,j,value);
			}
	}
	return 0;
}
