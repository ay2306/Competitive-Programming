#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    int *x = new int[m];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(i>0){
            arr[i-1]-=arr[i];
        }
    }
    for(int i = 0; i < m; ++i){
        int k;
        cin >> k;
        

    }

}