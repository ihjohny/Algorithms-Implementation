//Segment Tree (Recursive)
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100005
int tree[SIZE*3];
int arra[SIZE];

void init(int node,int b,int e) //tree construction function
{
	if(b==e)
	{
		tree[node]=arra[b];
		return ;
	}
	int mid=(b+e)/2;
	int left=(node*2);
	int right=(node*2)+1;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=tree[left]+tree[right];
	
}

int query(int node , int b, int e , int i, int j) // query function 
{
	if(i>e || j<b)
	{
		return 0;
	}
	if(b>=i && e<=j)
	{
		return tree[node];
	}
	int mid=(b+e)/2;
	int left=node*2;
	int right=(node*2)+1;
	int p1=query(left,b,mid,i,j);
	int p2=query(right,mid+1,e,i,j);
	return p1+p2;
}

void update(int node,int b, int e, int i, int newvalue)// tree re update function
{
	if(b>i||e<i)
	{
		return;
	}
	if(b==e)
	{
		tree[node]=newvalue;
		return;
	}
	int mid=(b+e)/2;
	int left=node*2;
	int right=(node*2)+1;
	update(left,b,mid,i,newvalue);
	update(right,mid+1,e,i,newvalue);
	tree[node]=tree[left]+tree[right];
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
	for(int i=0;i<operation;i++)
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
				int i,value;
				scanf("%d%d",&i,&value);
				update(1,1,x,i,value);
			}
	}
	return 0;
}
