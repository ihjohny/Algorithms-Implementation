#include<bits/stdc++.h>
#define SZ 100000
using namespace std;
int arra[SZ];
int temp[100];
//
void printfArra(int n)
{
    for(int i=1;i<=n;i++)
            cout<<arra[i]<<" ";
    cout<<endl;
}
//quick sort
void quicksorting(int low,int high)
{
    while(low>=high)
        return;
    //split
    int w,i,x;
    i=low;
    x=arra[low];
    for(int j=low+1;j<=high;j++)
    {
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
    //
    quicksorting(low,w-1);
    quicksorting(w+1,high);
}

//merge sort
void mergesorting(int startpoint, int endpoint)
{
	int midpoint;

	if(startpoint>=endpoint)
	{
		return ;
	}
	midpoint=(startpoint+endpoint)/2;

	mergesorting(startpoint,midpoint);
	mergesorting(midpoint+1,endpoint);

    //merge
	int first_arra=startpoint;
	int second_arra=midpoint+1;
	int i;
    for(i =first_arra;first_arra<=midpoint&&second_arra<=endpoint;i++)
	{

		if(arra[first_arra]<arra[second_arra])
		{
			temp[i]=arra[first_arra];
			first_arra++;
		}
		else
		{
			temp[i]=arra[second_arra];
			second_arra++;
		}

	}

		while(first_arra<=midpoint)
		{
			temp[i]=arra[first_arra];
			i++;
			first_arra++;
		}
		while(second_arra<=endpoint)
		{
			temp[i]=arra[second_arra];
			i++;
			second_arra++;
		}

    	for(i = startpoint; i<=endpoint; i++)
        arra[i] = temp[i];

}

int main()
{
  //  int arra[SZ];
    memset(arra,0,sizeof arra);
    int n;
    cout<<"Enter the number of elements :"<<endl;
    cin>>n;
    cout<<"Enter those elements"<<endl;
    for(int i=1;i<=n;i++)
        cin>>arra[i];
    int x;
    cout<<"Enter 1 for Quick sort"<<endl;
    cout<<"Enter 2 for Merge sort"<<endl;
    cin>>x;
    switch(x)
    {
        case 1:{
                    quicksorting(1,n);
                    printfArra(n);
                    break;
                }

        case 2:{
                    mergesorting(1,n);
                    printfArra(n);
                    break;
                }
    }
    return 0;
}
