//https://codeforces.com/problemset/problem/1291/B
#include<stdio.h>
const int N = 3e5+10;

int main(){
    int n,t,arr[N];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
        int i = 1, j = n, pos = 1;
        while(i <= j){
            if(arr[i] < (i-1) || arr[j] < (i-1))pos=0;
            i++, j--;
        }
        if(n%2 == 0 && arr[n/2] == arr[n/2+1] && arr[n/2] == n/2-1)pos = 0;
        pos==0?printf("No\n"):printf("Yes\n");
    }
    return 0;
}