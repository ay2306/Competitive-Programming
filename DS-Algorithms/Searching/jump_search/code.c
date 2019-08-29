#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int min(int a, int b){
    return (a>b)?b:a;
}
int jumpSearch(int arr[], int arr_size, int element){
    int step = sqrt(arr_size);
    int prev = 0;
    while(arr[min(step,arr_size)-1] < element){
        prev = step;
        step+=sqrt(arr_size);
        if(prev >= arr_size)return -1;
    }
    while(arr[prev] < element){
        prev++;
        if(prev == min(step,arr_size))return -1;
    }
    if(arr[prev] == element)return prev;
    return -1;
}

int main(){
    //Code for randomly creating an array
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
    printf("%d\n",jumpSearch(arr,arr_size,arr[rand()%arr_size]+1));
    return 0;

}