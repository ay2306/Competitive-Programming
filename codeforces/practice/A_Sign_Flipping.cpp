#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,arr[100];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i < n; ++i)scanf("%d",arr+i), arr[i] = (i%2 ? -abs(arr[i]) : abs(arr[i]));
        for(int i = 0; i < n; ++i)printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}