#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i)cin >> arr[i];
    int a[2];
    int min = arr[0]-arr[1];
    if(min<0)min*=-1;
    a[1] = 1;
    a[0] = 0;
    for(int i = 0; i < n; ++i){
        int j = (i + 1)%n;
        int d = arr[i]-arr[j];
        if(d<0)d*=-1;
        if(d < min){
            min = d;
            a[0] = i;
            a[1] = j;
        }
    
    }
    cout << a[0]+1 << " "  << a[1]+1;
    return 0;
}