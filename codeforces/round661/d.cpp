#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        queue<int> s[2];
        string a;
        cin >> a;
        int id = 0;
        vector<int> ans(n);
        for(char i: a){
            int u = i - '0';
            if(s[u^1].size()){
                ans[id++] = s[u^1].front();
                s[u].push(s[u^1].front());
                s[u^1].pop();
            }else{
                ans[id++] = ++cnt;
                s[u].push(cnt);
            }
        }
        cout << cnt << "\n";
        for(auto i: ans)cout << i << " ";
        cout << "\n";
    }
    return 0;
}