/*
QUESTION : SUPPOSE WE HAVE AN ARRAY (say) {1,2,3,4,5}
AND WE ROTATE IT SUCH THAT IT BECOMES {4,5,1,2,3}
NOW WE THINK ONLY POSSIBLE WAY TO SOLVE THIS IS LINEAR SEARCH
NO WE WILL TRY BINARY SEARCH BY FINDING PIVOT POINT
*/

#include <stdio.h> // HEADER INCLUDED IN ALL METHODS

//USEFUL COMMON FUNCTION(s)
void output(int arr[],int n){
int i ;
	for(i = 0; i < n; ++i){
		printf("%d  ",arr[i]);
	}
}
/*
NOTE: NO REPITION OCCURS HERE. IF REPITION OCCURS THEN JUST GO WITH LINEAR SEARCH(with time complexity of O(n)) AS BINARY SEARCH WILL BE CONFUSING THERE
TIME COMPLEXITY: O(log n)
*/

//FUNCTION PROTOTYPES
int binarySearch(int [], int, int, int);
int findPivot(int [], int, int);
int pivotedBinarySearch(int [], int, int);

//FUNCTION DEFINITIONS
int findPivot(int arr[], int low, int high){
	if(low>high)return -1; 
	if(high == low)return low;
	int mid = (low + high)/2;
	if(arr[mid]>arr[mid+1])return mid;
	if(arr[mid]<arr[mid-1])return (mid-1);
	if(arr[low]>arr[mid])return findPivot(arr,low,mid-1);
	return findPivot(arr,mid+1,high);
}
int pivotedBinarySearch(int arr[], int n, int key){
	int pivot  = findPivot(arr, 0, n-1);
	if(pivot == -1) //THIS MEANS ARRAY IS NOT ROTATED AT ALL
	{
		return binarySearch(arr,0,n-1,key);
	}
	if(arr[pivot]==key)return pivot;
	if(arr[0]<= key)return binarySearch(arr, 0, pivot - 1, key);
	return binarySearch(arr,pivot + 1, n-1, key);
	
}
int binarySearch(int arr[], int low, int high, int key){
	int mid = (high + low)/2;
	if(arr[mid]==key)return mid;
	if(arr[mid]>key)return binarySearch(arr,low,mid-1,key);
	if(arr[mid]<key)return binarySearch(arr,mid+1,high,key);
}

int main(){
	int arr[] = {5,6,7,8,9,10,1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int key = 6;
	printf("Index: %d", pivotedBinarySearch(arr,n,key));
	return 0;
}
