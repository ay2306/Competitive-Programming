#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
int arr[N];
int main(){
    int n,q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    while(q--){
        int ans = 0,x;
        cin >> x;
        for(int i = 0; i < n; ++i)if((arr[i] | x) == x)ans++;
        cout << ans << "\n";
    }
    return 0;
}