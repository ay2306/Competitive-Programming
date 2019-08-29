/*
	QUESTION: FIND IF THERE EXIST ANY TWO ELEMENTS IN AN ARRAY SUCH THAT THIER SUM IS EQUAL TO A PROVIDED NUMBER
	GIVEN: ARRAY IS SORTED BUT ROTATED
	NOTE: I HAD AN ERROR IN THIS PROBLEM BECAUSE INPUT WAS NOT SORTED. MAKE SURE THAT INPUT IS SORTED
*/
#include<stdio.h>
int pivotFinder(int arr[], int low, int high){
	int mid = (high + low)/2;
	printf("High: %d\tLow: %d\tMid: %d\n",high,low,mid);
	if(low > high)return 0;
	if(high == low)return 0;
	if(arr[mid]>arr[mid+1])return (mid+1);
	if(arr[mid]<arr[mid-1])return mid;
	if(arr[low]>arr[mid])return pivotFinder(arr,low,mid-1);
	return pivotFinder(arr,mid+1,high);
}

int check(int arr[], int sum, int n){
	int pivot = pivotFinder(arr,0,n-1);
	if(pivot == -1)pivot = 0;
	printf("PIVOT: %d\tn: %d\n",pivot,n);
	int i = pivot;
	int j = i-1;
	if(j<0){
		j+=n;
	}
	while( ((i>j)&&(i>=pivot)) || (i<j) ){
		printf("I: %d\tJ: %d\t arr[i]: %d\t arr[j]: %d\n",i,j,arr[i],arr[j]);
		if(arr[i]+arr[j]==sum)return 1;
		else if(arr[i]+arr[j] >sum){
			j--;
		}
		else if(arr[i]+arr[j] <sum){
			i++;
			i = i%n;
		}
		if(j<0){
            j+=n;
		}
	}
return 0;
}
int main(){
	int arr[] = {2,3,8,18,40,62,71};
	int sum = 26;
	int n = ((sizeof(arr))/(sizeof(arr[0])));
	if(check(arr,sum,n)){
		printf("YES");
	}else{
		printf("NO");
	}
}
