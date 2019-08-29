#include<stdio.h>
#include<stdlib.h>
void update(int arr[], int x, int val, int n){
    for(; x <= n; x+=(x&-x))arr[x]+=val;
}
int query(int arr[], int x, int n){
    int sum = 0;
    for(;x > 0; x-=(x&-x))sum+=arr[x];
    return sum;
}
long largest_power(long N){
    //changing all right side bits to 1.
    N = N| (N>>1);
    N = N| (N>>2);
    N = N| (N>>4);
    N = N| (N>>8);
    return (N+1)>>1;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int k = largest_power(n);
    int *arr = (int*)malloc(sizeof(int)*(n+1));
    int *BITS = (int*)calloc((1<<k)+1, sizeof(int));
    for(i = 0; i < n; ++i){
        scanf("%d",&arr[i+1]);
        update(BITS,i+1, arr[i+1],n);
    }
    printf("Sum of first 10 numbers %d\n",query(BITS,10,n));
    printf("Sum of 2-7 numbers %d",query(BITS,7,n)-query(arr,1,n));
}