#include<iostream>

using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n; ++i){
        int minimum = i;
        for(int j = i+1; j < n; ++j){
            if(arr[minimum]>arr[j])minimum=j;
        }
        swap(arr[i],arr[minimum]);
    }
}

int main(){
    int arr[54];
    for(int i = 54; i>0; --i){
        arr[i-1] = i;
    }
    selectionSort(arr,54);
    for(int i = 0; i < 54; ++i){
        cout << arr[i] << " ";
        if((i+1)%5==0)cout << endl;    
    }
    return 0;
}
