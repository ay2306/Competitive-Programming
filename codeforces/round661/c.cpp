#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for(int &i: a)cin >> i;
        for(int s = 0; s <= 2*n; ++s){
            unordered_map<int,int> m;
            int cnt = 0;
            for(int k: a){
                if(s-k > 0 && m[s-k])cnt++,m[s-k]--;
                else m[k]++;
            }
            ans = max(ans,cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}