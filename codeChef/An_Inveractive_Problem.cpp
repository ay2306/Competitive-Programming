#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> ans(n);
    auto countInversion = [&](int l, int r, int x)->int{
        int cnt = 0;
        l--,r--;
        while(l <= r)cnt+=ans[l] < x;
        return cnt;
    };
    auto query = [](int k, int x){
        return void(cout << "? " << k << " " << x << endl);
    };
    for(int i = n; i; i--){
        int lo = 1, hi = 1e6, res, cur, inversion;
        while(lo <= hi){
            int mid = lo + hi >> 1;
            //lets place 
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}