//bubble sort algorithm-code
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int arra[10]={12,144,1,25,3654,47,15,26,4,8};
	int i,j,temp;
	
	for(i=0;i<10;i++){
		for(j=0;j<10-1;j++){
			if(arra[j]>arra[j+1]){
				//swap operation
				temp=arra[j];
				arra[j]=arra[j+1];
				arra[j+1]=temp;
			}
		}
	 }

	for(i=0;i<10;i++){
		printf("%d ",arra[i]);
	}
	
	return 0;
}
