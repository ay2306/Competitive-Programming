#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    const ll N = 1e6;
    const ll n = 1e4;
    unordered_map<ll,int> m;
    for(ll i = 1; i < N; ++i){
        m[i*(3*i - 1)/2]++;
    }
    ll ans = LLONG_MAX;
    for(ll i = 1; i <= n; ++i){
        for(ll j = i+1; j <= n; ++j){
            ll a = i*(3*i - 1)/2;
            ll b = j*(3*j - 1)/2;
            ll dif = abs(a-b);
            ll s = a+b;
            if(m[s] > 0 && m[dif] > 0){
                ans = min(ans,dif);
            }
        }
    }
    cout << ans;
    return 0;
}