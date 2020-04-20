//https://codeforces.com/contest/535/problem/D
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll mod = 1e9+7;

long long power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%mod;
    long long p = power(a,n>>1);
    p=(p*p)%mod;
    if(n&1)p=(p*a)%mod;
    return p;
}

vector<int> zf(string &b){
    vector<int> z((int)b.size(),0);
    for(int i = 1, l = 0, r = 0; i < (int)b.size(); ++i){
        if(i <= r)z[i] = min(z[i-l],r-i+1);
        while(z[i]+i < b.size() && b[z[i]+i] == b[z[i]])++z[i];
        if(r < i+z[i]-1)l=i,r=z[i]+i-1;
    }
    return z;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n,k,last = 0,b,ans=0;
    string a;
    cin >> n >> k >> a;
    vector<int> z = zf(a);
    vector<pair<int,int>> arr(1,make_pair(0,0));
    for(int i = 0; i < k; ++i){
        cin >> b;
        if(b <= arr.back().second){
            if(z[b-arr.back().first] + b <= arr.back().second)return cout << 0 << "\n",0;
        }
        arr.emplace_back(b,b+a.size()-1);
    }
    if(arr.back().second != n)arr.emplace_back(n+1,n+1);
    for(int i = 1; i < arr.size(); ++i)ans+=max(arr[i].first-arr[i-1].second-1,0);
    return cout << power(26,ans) << "\n",0;
}