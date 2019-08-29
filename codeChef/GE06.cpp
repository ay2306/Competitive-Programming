/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <stdio.h>

void solve(){
    int arr[100100] = {0};
    for(int i = 2; i < 100100; ++i){
        if(arr[i] == 0){
            for(int j = 2; i*j < 100100; ++j){
                arr[i*j]++;
            }
        }
    }
    int n ;
    scanf("%d",&n);
    int cnt = 0;
    for(int i = 2; i < n; ++i){
        if(arr[i] == 0){
            // cout << i << " ";
            printf("%d ",i);
            cnt++;
        }
    }
    if(cnt == 0)printf("NO");
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}