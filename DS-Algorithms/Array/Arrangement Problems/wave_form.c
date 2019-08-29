/*
QUESTION: GIVEN AN ARRAY arr, SORT IT IN WAVE FORM
LIKE 1,2,3,4,5
BECOMES 2,1,4,3,5 OR 1,3,2,5,4
*/
#include <stdio.h>

//COMMON FUNCTIONS
void swap(int*, int*);

void swap(int *a, int *b){
	*a = *a+*b;
	*b = *a-*b;
	*a = *a-*b;
}

/*
METHOD 1
TIME COMPLEXITY: (O(n*log(n)))
*/
/*
void sort(int [], int);
void waveForm(int [], int);
void waveForm2(int [], int);
void sort(int arr[], int size){
	int swapped , i;
	while(1){
		swapped = 0;
		for(i = 0; i < (size-1); ++i){
			if(arr[i]>arr[i+1]){
				swap(&arr[i],&arr[i+1]);
				swapped = 1;
			}
		}
		if(swapped == 0){break;}
	}
}
void waveForm(int arr[], int size){
    int i = 0;
    for(; i < size-1; i+=2){
        swap(&arr[i],&arr[i+1]);
    }
}

void waveForm2(int arr[], int size){
    int i = 1;
    for(; i < size-1; i+=2){
        swap(&arr[i],&arr[i+1]);
    }
}

int main(){
	int arr[] = {5,4,3,2,1};
	int copy_arr[] = {5,4,3,2,1};
	int n = ((sizeof(arr))/(sizeof(arr[0])));
	sort(arr,n);
	waveForm(arr,n);
	int i;
	for(i = 0; i < n; i++){
		printf("%d\t",arr[i]);
	}
	sort(copy_arr,n);
	waveForm2(copy_arr,n);
	printf("\n");
	for(i = 0; i < n; i++){
		printf("%d\t",copy_arr[i]);
	}
	return 0;
}
*/
/*METHOD 2
TIME COMPLEXITY: O(n)
*/
void wave(int arr[], int size){
    int  i = 0;\
    for(i = 0; i < size; i+=2){
        if(i > 0 && arr[i-1]>arr[i])swap(&arr[i-1],&arr[i]);
        if(i < (size-1) && arr[i+1]>arr[i])swap(&arr[i+1],&arr[i]);
    }
}
int main(){
    int arr[] = {10,90,49,2,1,5,23};
	int n = ((sizeof(arr))/(sizeof(arr[0])));
	wave(arr,n);
	int i;
	for(i = 0; i < n; i++){
		printf("%d\t",arr[i]);
	}
    return 0;
}
