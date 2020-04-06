//https://codeforces.com/contest/1328/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll n,k;
    cin >> n >> k;
    ll lo = 0;
    ll hi = n-2;
    ll a = 0;
    while(lo <= hi){
        ll mi = lo + hi >> 1;
        if(((mi*(mi+1)) >> 1) < k){
            lo = mi+1;
            a = mi;
        }else{
            hi = mi-1;
        }
    }
    vector<char> ans(n,'a');
    ans[n-2-a] = 'b';
    lo = k-((a*(a+1))>>1);
    lo--;
    ans[n-1-lo]='b';
    cout << string(ans.begin(),ans.end()) << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}