//insertion_sort(iterative)
#include<iostream>
#include<cstdio>
#define SZ 10
using namespace std;
int main()
{
	int Arra[SZ]={777,55,45,2,14,878,4,145,14,99};
	int i,j,x;
	int count=0; //for counting time complixty (how many time the loop iterate)
	 
	for(i=1;i<SZ;i++)
	{
		x=Arra[i];
		j=i-1;
		while(Arra[j]>x && j>=0)
		{
			count++;
			Arra[j+1]=Arra[j];
			j--;
		}
		Arra[j+1]=x;
	}

	for(i=0;i<SZ;i++)
	{
		cout<<Arra[i]<<" ";
	}
	cout<<endl;
	cout<<"time compxity (loop iteration) "<<count<<endl;
	
return 0;
}
