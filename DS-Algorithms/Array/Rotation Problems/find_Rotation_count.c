/*
QUESTION: YOU ARE GIVEN A SORTED ARRAY ROTATED n TIMES.
WRITE A PROGRAM TO FIND OUT n
*/
#include <stdio.h>
/*

METHOD 1: BY LINEAR SEARCH METHOD
TIME COMPLEXITY: O(n)

*/

/*
int linearSearchPivotFinder(int arr[], int n){
	int i = 0;
	for(; i < (n-1); i++){
		if(arr[i]>arr[i+1])break;
	}
	i++;
return (n-i);
}

int main(){
	int arr[] = {5,6,7,8,1,2,3};
	printf("ARRAY WAS ROTATED %d TIMES",linearSearchPivotFinder(arr,(sizeof(arr)/sizeof(arr[0]))));
	return 0;
}
*/

/*
METHOD 2: BY BINARY SEARCH METHOD (BETTER WAY)
TIME COMPLEXITY: O(log(n))
*/
int binarySearchPivotFinder(int arr[], int low, int high){

	if(low > high)return -1;
	if(high == low) return low;
	int mid = (high + low)/2;
	if(arr[mid]>arr[mid+1])return (mid+1);
	if(arr[mid]<arr[mid-1])return mid;
	if(arr[low]>arr[mid])return binarySearchPivotFinder(arr,low,mid-1);
	return binarySearchPivotFinder(arr,mid+1,high);
}

int main(){
	int arr[] = {5,6,7,8,1,2,3};
	printf("ARRAY WAS ROTATED %d TIMES",((sizeof(arr)/sizeof(arr[0])) - binarySearchPivotFinder(arr,0,(sizeof(arr)/sizeof(arr[0])))));
	return 0;
}
