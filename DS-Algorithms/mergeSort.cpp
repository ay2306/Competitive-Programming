#include<iostream>
#include<limits.h>
using namespace std;


void mergeSort(int arr[], int start, int end){
    if(start == end)return;
    int mid = (start + end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    int left_size = mid-start;
    left_size++;
    int right_size = end-mid;
    int *left = new int[left_size+1];
    int *right = new int[right_size+1];
    int o = 0;
    for(int i = start; i <= mid; ++i)left[o++] = arr[i];
    o = 0;
    for(int i = mid+1; i <= end; ++i)right[o++] = arr[i];
    int i = 0;
    int j = 0;
    left[left_size] = INT_MAX;
    right[right_size] = INT_MAX;
    for(int k = start; k <= end; ++k){
        /*if(i>=left_size){
            arr[k] = right[j];
            ++j;
        }else if(j>=right_size){
            arr[k] = left[i];
            ++i;
        }else{*/
            if(left[i]<=right[j]){
                arr[k] = left[i];
                ++i;
            }else{
                arr[k] = right[j];
                ++j;
            }
        //}
    }
}

int main(){
    int arr[] = {6,5,4,3,2,1};
    mergeSort(arr,0,5);
    for(int i = 0; i < 6; ++i)cout << arr[i] << " ";
}