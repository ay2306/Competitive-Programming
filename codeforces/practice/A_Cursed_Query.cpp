#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    int n,q,a;
    cin >> n >> q;
    int cur = 0;
    vector<pair<int,int>> arr;
    for(int i = 0; i < n; ++i){
        cin >> a;
        arr.emplace_back(cur,cur+a-1);
        cur+=a;
    }
    const int mod = cur;
    while(q--){
        cin >> a;
        a%=mod;
        int index = upper_bound(arr.begin(),arr.end(),make_pair(a,LLONG_MAX)) - arr.begin();
        cout << index << "\n";
    }
    return 0;
}