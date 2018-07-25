//selection_sort(iterative)
#include<iostream>
#include<cstdio>
#define SZ 10
using namespace std;
int main()
{
	int Arra[SZ]={777,55,45,2,14,878,4,145,14,99};
	int i,j,k,temp;
	int count=0; //for counting time complixty (how many time the loop iterate)
	 
	for(i=0;i<SZ-1;i++)
	{
		for(j=i+1;j<SZ;j++)
		{
			count++; //for counting loop intertion
			
			if(Arra[j]<Arra[k])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			//swaping
			temp=Arra[i];
			Arra[i]=Arra[k];
			Arra[k]=temp;
		}
	}
	
	//print
	for(i=0;i<SZ;i++)
	{
		cout<<Arra[i]<<" ";
	}
	cout<<endl;
	cout<<"time compxity (loop iteration) "<<count<<endl;
	
return 0;
}
