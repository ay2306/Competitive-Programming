#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N,K;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> N >> K;
    vector<ll> a(N);
    for(auto &i: a)cin >> i;
    if(accumulate(a.begin(),a.end(),0LL) > K){
        cout << -1;
        return 0;
    }
    K-=accumulate(a.begin(),a.end(),0LL);
    ll req = 0;
    vector<ll> b(N,0);
    for(int _bit = 40; _bit >= 0; --_bit){
        int avail = 0;
        if((K>>_bit)&1)req++;
        for(int i = 0; i < N; ++i){
            if(((a[i]>>_bit)&1) == 0 && req > 0){b[i]+=((1LL << _bit));req--;}
        }
        req*=2;
    }
    if(req == 0){
        for(auto &i: b)cout << i << " ";
    }
    else cout << -1;
    return 0;
}