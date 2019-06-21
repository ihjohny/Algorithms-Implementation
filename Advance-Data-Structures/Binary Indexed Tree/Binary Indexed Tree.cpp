//Binary Indexed Tree
//By MD.Imam Hossain Johny
//Dept. ICE, NSTU-11 batch
#include<bits/stdc++.h>
#define N 10 
using namespace std;
int tree[11]={0}; 

void update(int index,int x) // for updating value into the BIT
{
	while(index<=N)
	{
		tree[index]+=x;
		index+=( index & -index);
	}
}
int sum(int index)//for query desired index sum
{
	int res=0;
	while(index>0)
	{
		res+=tree[index];
		index-=( index & -index);
	}
	return res;
}
int main()
{
	int array[20]={10,20,30,40,50,60,70,80,90,100}; //10 sample value
	for(int i=0;i<10;i++)//updating array element into binary indexed tree
	{
		printf("%d ",array[i]);
		update(i+1,array[i]); //tree index start from 1 , so i+1 used
	}
	
	printf("\nEnter index for summation form 1 to given index\n");
	while(1)
	{
		int index;
		scanf("%d",&index);
		if(index==0)
			break;
		printf("Summation of value from index 1 to %d = %d\n",index,sum(index));
	}
	
	return 0;
}
