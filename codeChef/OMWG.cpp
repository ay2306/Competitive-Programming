#include<iostream>
using namespace std;
int sol(int arr[][], int i, int n, int m){
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        int arr[1000][1000];
        cin >> n >> m;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j)arr[i][j]=0;
        }
        cout << sol(arr,0,n,m)
    }
}