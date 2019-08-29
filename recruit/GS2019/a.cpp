#include <bits/stdc++.h>


#define ll long long int
using namespace std;
const int N = 1e6+10;
int pp[N];
const ll mod = 1e9+7;

ll f(ll n, ll k)
{
    ll C[k+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;  // nC0 is 1

    for (ll i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = (C[j]%mod + C[j-1]%mod)%mod;
    }
    return C[k];
}


int getSubsets(int k, int n, vector<int> arr) {
    for(int i = 2; i < N; ++i){
        if(pp[i] == 0){
            for(int j = 1; i*j < N; ++j)pp[i*j] = i;
        }
    }
    ll ps = 0;
    unordered_map<ll,ll> m;
    for(auto &i: arr){
        int t = i;
        if(t < 2)continue;
        while(t > 1){
            int k = pp[t];
            m[k]++;
            while(t > 1 && t % k == 0){
                t/=k;
            }
        }
    }
    for(auto &i: m){
        ps+=(i.first*i.second);
    }

    ps%=(1000000);
    return f(ps+k-1,k-1)%mod;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)cin >> arr[i];
    cout << getSubsets(k,n,arr);
    return 0;
}