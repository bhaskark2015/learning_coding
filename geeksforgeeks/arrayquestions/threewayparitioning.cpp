/*
Three way partitioning of an array around a given range
Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts.
1) All elements smaller than lowVal come first.
2) All elements in range lowVal to highVVal come next.
3) All elements greater than highVVal appear in the end.
The individual elements of three sets can appear in any order.

Examples:

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}  
        lowVal = 14, highVal = 20
Output: arr[] = {1, 5, 4, 2, 1, 3, 14, 20, 20, 98, 87, 32, 54}

Input: arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32}  
       lowVal = 20, highVal = 20       
Output: arr[] = {1, 14, 5, 4, 2, 1, 3, 20, 20, 98, 87, 32, 54} 

*/
//#define swap(a,b) int temp=a;a=b;b=temp;


#include <iostream>
#include <algorithm>
using namespace std;

void printIntarray(int arr[],int length){

	for(int i=0;i<length;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(int argv,char* argc[]){
	int arr[] = {1, 14, 5, 20, 4,2, 54, 20, 87, 98, 3, 1, 32} ;
	int length= sizeof(arr)/sizeof(int);
	int lowerIndex=-1,higherIndex=-1;
	int lowerVal=5;
	int higherVal=20;

	for(int i=0;i<length;i++){
		cout<<"lower index is at "<<lowerIndex<<" and higherIndex is at "<<higherIndex<<" and i is "<<i<<endl;
		if(arr[i] < lowerVal){
			lowerIndex++;
			higherIndex++;
			swap(arr[i],arr[lowerIndex]);
			swap(arr[i],arr[higherIndex]);
		}
		else if(arr[i] <= higherVal){
			higherIndex++;
			swap(arr[i],arr[higherIndex]);
		}
		printIntarray(arr,length);
	}

	return 0;
}