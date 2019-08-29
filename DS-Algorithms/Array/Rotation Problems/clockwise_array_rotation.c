/*
ROTATION OF AN ARRAY BY ONE (CAN BE DONE BY N VIA LOOP)
SAMPLE:
INPUT = {1,2,3,4,5}
OUTPUT = {5,1,2,3,4}
*/

#include <stdio.h> // HEADER INCLUDED IN ALL METHODS

//FUNCTION PROTOTYPING
void rotateClockwise(int [], int);

//USEFUL COMMON FUNCTION(s)
void output(int arr[],int n){
int i ;
	for(i = 0; i < n; ++i){
		printf("%d  ",arr[i]);
	}
	//printf("\n");
}

void rotateClockwise(int arr[], int sizeOfArray){
	int tmp = arr[sizeOfArray - 1];
	int i;
	for(i = sizeOfArray-1 ; i > 0; --i){
		arr[i]=arr[i-1];
	}
	arr[0] = tmp;
}

int main(){
	int arr[] = {1,2,3,4,5};
	rotateClockwise(arr,5);
	output(arr,5);
	return 0;
}