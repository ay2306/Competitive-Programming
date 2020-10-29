#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1010;
vector<int> g[N];
int a[N];
signed main(){
    int n,k;
    cin >> n >> k;
    int base,mn = LLONG_MIN;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    for(int i = 1; i <= n; ++i){
        int len = 0;
        for(int j = i; j <= n; ++j){
            len += (a[j] == a[i] + (j-i) * k);
        }
        if(len > mn && a[i] - (i-1)*k > 0){
            mn = len;
            base = a[i] - (i-1)*k;
        }
    }

    vector<pair<int,int>> res;
    for(int i = 1; i <= n; ++i){
        if(base + (i-1) * k  == a[i])continue;
        res.emplace_back(i, base + (i-1) * k  - a[i]);
    }
    cout << res.size() << "\n";
    for(auto &i: res){
        if(i.second < 0)cout << "- ";
        else cout << "+ ";
        cout << i.first << " " << abs(i.second) << "\n";
    }
    return 0;
}