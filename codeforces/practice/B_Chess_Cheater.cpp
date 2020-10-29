#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

void solve(){
    int n,k,ans=0,cnt = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char,int>> a;
    for(char i: s){
        if(a.size() == 0 || a.back().first != i)a.emplace_back(i,1);
        else a.back().second++;
    }
    int wins = 0, streak = 0;
    for(auto i: a)if(i.first == 'W')wins+=i.second,streak++;
    if(wins + k >= n)return void(cout << 2*n-1 << "\n");
    if(wins == 0)return void(cout << max(2*k-1,0) << "\n");
    vector<int> losing;
    int extra = 0;
    for(int i = 0; i < a.size(); ++i){
        if(a[i].first == 'W')continue;
        if(i == 0 || i+1 == a.size())extra += a[i].second;
        else losing.emplace_back(a[i].second);
    }
    sort(losing.begin(),losing.end());
    for(auto i: losing){
        if(k == 0)break;
        if(k >= i)streak--;
        i = min(k,i);
        k-=i;
        wins+=i;
    }
    extra = min(k,extra);
    wins+=extra;
    cout << 2*wins - streak << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}