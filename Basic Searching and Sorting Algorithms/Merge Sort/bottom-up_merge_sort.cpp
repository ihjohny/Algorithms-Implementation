//bottom-up_merge_sort
#include<iostream>
#define SZ 100
using namespace std;
int arra[SZ]={0,777,55,45,2,14,878,4,145,14,99}; //first element( arra[0] )is not considering while sorting 
int temp[100]; //temporary arra for storing temporary merge result
int count=0; //for counting time complixty (how many time the loop iterate)
	
void merge(int startpoint,int midpoint,int endpoint)
{
	int first_arra=startpoint;
	int second_arra=midpoint+1;
	int k=first_arra;
    while(first_arra<=midpoint && second_arra<=endpoint)
	{
		count++; //for calculating how many time the loop iterate		 
		if(arra[first_arra]<arra[second_arra])
		{
			temp[k]=arra[first_arra];
			first_arra++;
		}
		else
		{
			temp[k]=arra[second_arra];
			second_arra++;
		}
		
		k=k+1;

	}

		while(first_arra<=midpoint)
		{
			temp[k]=arra[first_arra];
			k++;
			first_arra++;
		}
		while(second_arra<=endpoint)
		{
			temp[k]=arra[second_arra];
			k++;
			second_arra++;
		}

    	for(int i = startpoint; i<=endpoint; i++)
    	{
			arra[i] = temp[i];  //copying all element from temp to arra after merge
		}
}

int main()
{

	//bottom up merge sorting 
	int t,s,i,n;
	n=10;
	t=1;
	while(t<n)
	{
		s=t;t=2*s;i=0;
		while(i+t<=n)
		{
			merge(i+1,i+s,i+t);
			i=i+t;
		}
		if( (i+s)<n )
		{
			merge(i+1,i+s,n);
		}
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<arra[i]<<" ";
	}
	cout<<endl;
	cout<<"time compxity (loop iteration) "<<count<<endl;
	
	return 0;
}
