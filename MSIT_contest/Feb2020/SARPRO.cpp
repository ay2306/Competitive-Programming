#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector<int> dp(n,0),q;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        auto it = lower_bound(q.begin(),q.end(),a);
        if(it == q.end())q.emplace_back(a);
        else *it = a;
        it = lower_bound(q.begin(),q.end(),a);
        dp[i]=it-q.begin();
    }
    int ans = *max_element(dp.begin(),dp.end());
    for(int i = 0; i+1 < n; ++i){
        if(dp[i] == ans){
            ans++;
            break;
        }
    }
    cout << ans+1;
    return 0;
}