/*
QUESTION: GIVEN AN ARRAY arr[], ARRANGE IT IN A WAY SUCH THAT Summation(i*arr[i]) IS MAXIMUM
*/
#include <stdio.h>

/*
    METHOD 1: NAIVE SOLUTION
    TIME COMPLEXITY: O(n*n)
*/
/*
int rotate(int [], int);
int summation(int [], int);
int findMaxSummation(int [], int);
int summation(int arr[], int n){
	int i;
	int sum = 0;
	for(i = 0; i < n; i++){
		sum+=(i*arr[i]);
	}
return sum;
}
int findMaxSummation(int arr[], int n){
int max = 0;
int i;
int tmp = summation(arr,n);
if(max<tmp)max=tmp;
	for(i = 1; i < n; ++i){
		rotate(arr,n);
		tmp = summation(arr,n);
		if(max < tmp)max = tmp;
	}
return max;
}

int rotate(int arr[], int n){
	int  tmp = arr[0];
	int i;
	for(i = 0; i < (n-1); ++i){
		arr[i] = arr[i+1];
	}
	arr[i] = tmp;
}

int main(){
	int arr[] = {3,2,1};
	printf("MAXIMUM: %d",findMaxSummation(arr,(sizeof(arr)/sizeof(arr[0]))));
	return 0;
}

*/

/*
METHOD 2: BETTER WAY
TIME COMPLEXITY: O(n)
EXPLANATION:
	SUMMATION OF ARRAY, arr (say) is 0*arr[0] + 1*arr[1] + 2*arr[2] + ... + (n-1)*arr[n-1] ...(1)
	AFTER A ROTATION, (n-1)arr[0] + 0*arr[1] + 1*arr[2] + ... + (n-2)*arr[n-1] ...(2)
	INCREASE IN SUM IS EQUATION (2) - EQUATION (1) i.e.
	(n)arr[0] - sum of elements of array
*/

int findMaxSummation(int arr[], int n){
	int i,j,sumOfArray;
	int sum, max = 0;
	sumOfArray = 0;
	sum = 0;
	for(i = 0; i < n; ++i){
		sum+=(arr[i]*i);
		sumOfArray+=arr[i];
	}
	if(max < sum)max = sum;
	i=0;
	while(i < (n-1)){
		sum+=n*arr[i];
		sum-=sumOfArray;
		if(max < sum)max = sum;
		++i;
	}
return max;
}

int main(){
	int arr[] = {1,2,3};
	printf("MAXIMUM SUM = %d", findMaxSummation(arr, (sizeof(arr)/sizeof(arr[0]))));
	return 0;
}
