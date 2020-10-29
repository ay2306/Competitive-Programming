#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> uid(INT_MAX/2,INT_MAX);
    const int mod = 1e9+7;
    const int prime = uid(rng);
    auto hash = [prime](string &s)->int{
        int h = 0,k = 0;
        for(char i: s){
            h = h * prime % mod % i * i * k % mod;
            if(h >= mod)h %= mod;
            k++;
        }
        return h;
    };
    int n,m;
    cin >> n >> m;
    set<int> cnt;
    while(n--){
        string a;
        cin >> a;
        cnt.emplace(hash(a));
    }
    while(m--){
        string a;
        cin >> a;
        for(char &i: a){
            char ori
        }
    }
}