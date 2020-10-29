#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    cin >> a >> b;
    int ans = INT_MAX;
    if(b.size() > a.size()){
        cout << "-1\n";
        return;
    }
    for(int i = 0; i + b.size() - 1 < a.size(); ++i){
        string temp = a;
        int cnt = 0;
        for(int j = 0; j < b.size(); ++j){
            cnt += temp[i+j] != b[j];
            temp[i+j] = b[j];
        }
        for(int l = 0, r = a.size() - 1; l < r; ++l,r--){
            if(temp[l] != temp[r]){
                if(l >= i && l <= i+b.size()-1 && r >= i && r <= i+b.size()-1){
                    cnt = INT_MAX;
                    break;
                }
                cnt += 1;
            }
        }
        ans = min(ans,cnt);
    }
    if(ans == INT_MAX)cout << "-1\n";
    else cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}