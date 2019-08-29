#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
    ll n,a,o,s=0;
    cin >> n;
    ll *arr = new ll[n];
    for(ll i = 0; i < n; ++i){
        o = 0;
        for(ll j = 0; j < n; ++j){
            cin >> a;
            if(a == 1)o++;
        }
        arr[i] = o*(1 << (n-o));
        s+=arr[i];
    }
    // for(ll i = 0; i < n; ++i){

    // }
    cout << s << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}