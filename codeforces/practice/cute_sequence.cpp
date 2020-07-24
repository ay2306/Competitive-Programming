//https://codeforces.com/problemset/problem/1166/D
#include<bits/stdc++.h>
#define SUM(a) accumulate(a.begin(),a.end(),0LL)
using namespace std;

long long p(long long n){
    if(n <= 0)return 1;
    return (1LL<<n);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,b,m;
        scanf("%lld%lld%lld",&a,&b,&m);
        int n = 2;
        if(a == b){
            printf("1 %lld\n",a);
            continue;
        }
        bool found = false;
        while(1){
            if(p(n-2)*(a+1) <= b && b <= p(n-2)*(a+m)){
                found = true;
                break;
            }
            if(p(n-2)*(a+1) > b)break;
            n++;
        }
        if(!found){
            printf("-1\n");
            continue;
        }
        vector<long long> ans(n);
        ans[0] = a;
        

    }
    return 0;
}