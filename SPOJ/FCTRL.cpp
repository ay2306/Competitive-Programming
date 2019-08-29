#include<bits/stdc++.h>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int a,temp,two = 0,five = 0,k=2;
        scanf("%lld",&a);
        while(a >= k){
            two+=(a/k);
            k*=2;
        }
        k = 5;
        while(a >= k){
            five+=(a/k);
            k*=5;
        }
        printf("%lld\n",std::min(five,two));
    }
    return 0;
}