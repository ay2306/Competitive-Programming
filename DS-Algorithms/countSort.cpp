#include<iostream>
#define RANGE 9
using namespace std;

void count_sort(int arr[],int n){
    //int n = ((sizeof(arr))/(sizeof(arr[0])));
    int cnt[RANGE+1] = {0};
    for(int i = 0; i <= RANGE; ++i)cnt[i]=0;
    int *output = new int[n];
    for(int i = 0; i < n; ++i){
        cnt[arr[i]]++;
    }
    for(int i = 1; i <= RANGE; ++i)cnt[i]+=cnt[i-1];
    for(int i = 0; i < n; ++i){
        output[cnt[arr[i]]-1] = arr[i];
        --cnt[arr[i]];
    }
    for(int i = 0; i < n; ++i){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {1,4,1,2,7,5,2};
    int n = ((sizeof(arr))/(sizeof(arr[0])));
    count_sort(arr,n);
    for(int i = 0; i < n; ++i)cout << arr[i] << " ";
    return 0;
}
