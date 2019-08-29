#include<bits/stdc++.h>
using namespace std;

void solve(){
    long n;
    cin >> n;
    vector<long long int> arr(n);
    vector<long long int> diff(n,0);
    for(long i = 0; i < n; ++i)cin >> arr[i];
    for(long i = 1; i < n; ++i)diff[i] = arr[i]-arr[i-1];
    long ans = 2;
    for(int i = 1; i < n; ++i){
        if(diff[i] >= 0 && diff[i-1] < 0)ans++;
    }
    cout << ans << "\n";
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}