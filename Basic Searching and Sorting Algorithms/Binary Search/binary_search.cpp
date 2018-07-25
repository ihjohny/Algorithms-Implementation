//Binary_Search
#include<iostream>
#define SZ 20
using namespace std;
int main()
{
	int Arra[SZ]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int x;
	cout<<"Enter the number for search"<<endl;
	cin>>x;
	
	int count=0; //for counting time complixty (how many time the loop iterate)
	
	//binary search
	int low,high,j,mid;
	low=0,high=SZ,j=0;
	while(low<=high && j==0)
	{
		count++;
		mid=(low+high)/2;
		if(x==Arra[mid]) 
		{
			j=mid+1;  //mid+1 Because Arra indexing start from 	0
		}
		else if(x<Arra[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	
	if(j!=0)
	{
		cout<<"The item "<<x<<" is found on index "<<j<<endl;
		cout<<"time compxity (loop iteration) "<<count<<endl;
	}
	else
	{
		cout<<"The item is not found"<<endl;
		cout<<"time compxity (loop iteration) "<<count<<endl;
	}
	
	return 0;
}
