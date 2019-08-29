#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int arr[N];
vector<int> primes;
void solve(int t){
    int l,r;
    cin >> l >> r;
    int ans = 0;
    int a = upper_bound(primes.begin(),primes.end(),(l-1)/4) - primes.begin();
    int b = upper_bound(primes.begin(),primes.end(),r/4) - primes.begin();
    ans+=(b-a);
    a = upper_bound(primes.begin(),primes.end(),l-1) - primes.begin();
    b = upper_bound(primes.begin(),primes.end(),r) - primes.begin();
    ans+=(b-a);
    ans+=(max(r-2,0)/4-max(l-3,0)/4);
    if(l <= 4 && 4 <= l)ans++;
    if(l <= 1 && 1 <= r)ans++;
    printf("Case #%d: %d\n",t,ans);
}
int main(){
    for(int i = 2; i < N; ++i){
        if(arr[i] > 0)continue;
        for(int j = 2; i*j < N; ++j){
            arr[i*j]++;
        }
    }
    for(int i = 2; i < N; ++i){
        if(arr[i] == 0)primes.push_back(i);
    }
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        solve(i);
    }
}
