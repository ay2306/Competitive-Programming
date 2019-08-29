#include<iostream>

using namespace std;

int array_partition(int arr[], int low, int high){
int pivot = arr[high];
int i = low-1;
for(int j = low; j < high; ++j){
    if(arr[j]<=pivot){
        ++i;
        swap(arr[i],arr[j]);
    }
}
++i;
swap(arr[i],arr[high]);
return i;
}
void print_arr(int arr[], int n){
    for(int i = 0; i <= n; ++i)cout << arr[i]<< " ";
    cout << endl;
}
void quick_sort(int arr[], int low, int high){
    if(low<high){
        int prev_pivot = array_partition(arr,low,high);
        cout << "Prev pivot pos " << prev_pivot << endl;
        print_arr(arr,high-low);
        quick_sort(arr,low,prev_pivot-1);
        quick_sort(arr,prev_pivot+1,high);
    }
}

int main(){
int arr[] = {10,80,30,90,40,50,70};
int n = ((sizeof(arr))/(sizeof(arr[0])));
quick_sort(arr,0,n-1);
for(int i = 0; i < n; ++i)cout << arr[i] << " ";
return 0;
}
