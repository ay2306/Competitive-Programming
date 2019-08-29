#include<bits/stdc++.h>
using namespace std;

void solve(){
    int arr[5100];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    sort(arr,arr+n);
    int ans = arr[1]-arr[0];
    for(int i = 2; i < n; ++i)ans = min(arr[i]-arr[i-1],ans);
    cout << ans << endl;
}


int main(){
    int t;
    cin >> t;
    while(t--)solve();
}