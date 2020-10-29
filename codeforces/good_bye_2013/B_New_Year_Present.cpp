#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int &i: arr)scanf("%d",&i);
    for(int i = 0; i < n; ++i){
        while(arr[i]--){
            printf("P");
            if(i != n-1 && arr[i])printf("RL");
            else if(arr[i])printf("LR");
        }
        if(i != n-1)printf("R");
    }
    return 0;
}