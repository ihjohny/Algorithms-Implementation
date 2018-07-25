//quick sort
#include<iostream>
#define SZ 100
using namespace std;
int arra[SZ]={777,55,45,2,14,878,4,145,14,99}; 
int temp[100]; //temporary arra for storing temporary merge result
int count=0; //for counting time complixty (how many time the loop iterate)

int split(int low,int high)
{
	int w,i,x;
    i=low;
    x=arra[low];
    for(int j=low+1;j<=high;j++)
    {
		count++; //for calculating how many time the loop iterate		
        if(arra[j]<=x)
        {
            i=i+1;
            if(i!=j)
            {
                //swap
                int tmp=arra[i];
                arra[i]=arra[j];
                arra[j]=tmp;
            }
        }
    }
    int tmp=arra[i];
    arra[i]=arra[low];
    arra[low]=tmp;
    w=i;
    return w;
}
void quick_sort(int low,int high)
{
	if(low<high)
	{
		int w=split(low,high);
		quick_sort(low,w-1);  
		//the middle "w" will be sorted in it's own position so we are taking w-1,and w+1
		quick_sort(w+1,high);
	}
}

int main()
{
	//quick sorting(divide and conquer)
	int n=10;
	quick_sort(0,n-1); //sorting from index 0 to n-1
	
	for(int i=0;i<n;i++)
	{
		cout<<arra[i]<<" ";
	}
	cout<<endl;
	cout<<"time compxity (loop iteration) "<<count<<endl;
}
