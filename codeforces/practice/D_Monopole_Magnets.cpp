#include<bits/stdc++.h>
using namespace std;

vector<string> a;
int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    int emptyRow = 0, emptyCol = 0;
    for(auto &i: a)cin >> i;
    for(int i = 0; i < n; ++i){
        vector<int> k;
        int cnt = 0;
        for(int j = 0; j <= m; ++j){
            if(j == m || a[i][j] == '.'){
                if(cnt)k.emplace_back(cnt);
                cnt = 0;
            }else cnt++;
        }
        emptyRow|=(k.size()==0);
        if(k.size() > 1)return cout << -1 , 0;
    }
    for(int i = 0; i < m; ++i){
        vector<int> k;
        int cnt = 0;
        for(int j = 0; j <= n; ++j){
            if(j == n || a[j][i] == '.'){
                if(cnt)k.emplace_back(cnt);
                cnt = 0;
            }else cnt++;
        }
        if(k.size() > 1)return cout << -1 , 0;
        emptyCol|=(k.size()==0);
    }
    if(emptyRow ^ emptyCol)return cout << -1,0;
    function<void(int,int)> dfs = [&](int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] == '.')return;
        a[i][j] = '.';
        dfs(i+1,j),dfs(i-1,j),dfs(i,j-1),dfs(i,j+1);
    };
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(a[i][j] == '#')dfs(i,j),ans++;
    return cout << ans, 0;
}