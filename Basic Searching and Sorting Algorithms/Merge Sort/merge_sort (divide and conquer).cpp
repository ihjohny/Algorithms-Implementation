//merge_sort
/* 
 * Stable
 * Not in place
 * Best case complexity O(nlogn)
 * Average case complexity O(nlogn)
 * Worst case complexity O(nlogn)
 * Space complexity O(n)
 * 
 */
#include<iostream>
#define SZ 100
using namespace std;
int arra[SZ]={777,55,45,2,14,878,4,145,14,99}; 
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

void merge_sort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}

int main()
{

	//merge sorting(divide and conquer)
	int n=10;
	merge_sort(0,n-1); //sorting from index 0 to n-1
	
	for(int i=0;i<n;i++)
	{
		cout<<arra[i]<<" ";
	}
	cout<<endl;
	cout<<"time compxity (loop iteration) "<<count<<endl;
	
	return 0;
}
