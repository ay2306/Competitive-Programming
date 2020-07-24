//https://codeforces.com/contest/1360/problem/H
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<long long> c;
    for(int i = 0; i < n ; ++i){
        string a;
        cin >> a;
        long long val = 0;
        for(char i: a)val = (val*2LL + (i=='1'));
        c.emplace_back(val);
    }
    // for(auto i: c)cout << i << " ";
    // cout << endl;
    sort(c.begin(),c.end());
    long long lo = 0;
    long long hi = (1LL << m)-1;
    long long ans = hi;
    long long target = (((1LL << m) - n) >> 1) + (n&1);
    // printf("Target = %lld\n",target);
    while(lo <= hi){
        long long mi = lo + hi >> 1;
        long long del = upper_bound(c.begin(),c.end(),mi) - c.begin();
        long long tot = mi - del + 1;
        if(tot == target)ans = mi, hi = mi-1;
        else if(tot < target)lo = mi+1;
        else hi = mi - 1;
        // printf("mi = %lld, del = %lld, tot = %lld, lo = %lld, hi = %lld\n",mi,del,tot,lo,hi);
    }
    // printf("ans = %lld\n",ans);
    string arr = "";
    while(ans){
        arr+=(char('0'+ans%2));
        ans/=2;
    }
    reverse(arr.begin(),arr.end());
    arr = string(m-arr.size(),'0')+arr;
    cout << arr << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    solve();
    return 0;
}