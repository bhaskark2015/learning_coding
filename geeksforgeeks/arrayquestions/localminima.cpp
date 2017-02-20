/*Find a local minima in an array
Given an array arr[0 .. n-1] of distinct integers, the task is to find a local minima in it. We say that an element arr[x] is a local minimum if it is less than or equal to both its neighbors.

For corner elements, we need to consider only one neighbor for comparison.
There can be more than one local minima in an array, we need to find any one of them.
Examples:

Input: arr[] = {9, 6, 3, 14, 5, 7, 4};
Output: Index of local minima is 2
The output prints index of 3 because it is 
smaller than both of its neighbors. 
Note that indexes of elements 5 and 4 are 
also valid outputs.

Input: arr[] = {23, 8, 15, 2, 3};
Output: Index of local minima is 1

Input: arr[] = {1, 2, 3};
Output: Index of local minima is 0

Input: arr[] = {3, 2, 1};
Output: Index of local minima is 2*/
#include <iostream>
using namespaces std;
int main(){
	int arr[]={9, 6, 3, 14, 5, 7, 4};
	int len= sizeof(arr)/sizeof(int);

	int localMinimaindex=0;
	for(int i=0;i<len;i++){
		if(i>0 ){
			if(i<=len -1){
				
			}
		}
		else if(arr[i]>)
	}

}