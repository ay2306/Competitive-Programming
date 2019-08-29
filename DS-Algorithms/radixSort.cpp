#include<iostream>
#define RANGE 9
using namespace std;

void count_sort(int arr[],int n, int exp)
{
    int *output = new int[n];
    int cnt[RANGE + 1] = {0};
    for(int i = 0; i < n; ++i)cnt[(arr[i]/exp)%10]++;
    for(int i = 1; i <= RANGE; ++i)cnt[i]+=cnt[i-1];
    for(int i = n-1; i >= 0; --i){
        output[cnt[(arr[i]/exp)%10]-1] = arr[i];
        cnt[(arr[i]/exp)%10]--;
    }
    for(int i = 0; i < n; ++i){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int maximum = 0 ;
    for(int i = 0; i < n; ++i){
        if(maximum<arr[i])maximum=arr[i];
    }
    for(int exp = 1; maximum/exp > 0; exp*=10){
        count_sort(arr,n,exp);
//         for(int i = 0; i < n; ++i)cout << arr[i] << " ";
//         cout << endl;   
    }
    
}
int main(){
    int arr[] = {2,24,45,66,75,90,170,802};
    int n = ((sizeof(arr))/(sizeof(arr[0])));
//     cout << "ORGINAL ARRAY: " ;
//     for(int i = 0; i < n; ++i)cout << arr[i] << " ";
//     cout << endl;   
    radixSort(arr,n);
    for(int i = 0; i < n; ++i)cout << arr[i] << " ";
    return 0;
}

