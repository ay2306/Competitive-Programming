#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binary_search(int arr[], int arr_size, int element){
    int low = 0;
    int high = arr_size-1;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(arr[mid] == element)return mid;
        if(arr[mid] > element) high = mid - 1;
        if(arr[mid] < element) low = mid + 1; 
    }
return -1;
}

int main(){
    srand(time(0));
    int arr_size = (rand()%50000 + 50); //Means size lie between 50 to 149
    int i;
    int *arr = (int*)malloc(sizeof(int)*arr_size);
    int lowerLimit = 10;
    int maxLimit = 50;
    for(i = 0; i < arr_size; ++i){
        arr[i] = (rand()%maxLimit)+lowerLimit;
        lowerLimit = arr[i];
        
    }
    printf("%d" ,binary_search(arr, arr_size, arr[5]));
    printf("\n");
    return 0;
}