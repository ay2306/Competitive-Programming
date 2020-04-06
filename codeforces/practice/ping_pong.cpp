//https://codeforces.com/problemset/problem/320/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;

bool check(pair<int,int> a, pair<int,int> b){
  if(a.first < b.first && b.first < a.second)return true;
  if(a.first < b.second && b.second < a.second)return true;
    return false;
}
vector<pair<int,int>> arr;
vector<int> g[110];
int vis[110];

void dfs(int s){
    vis[s] = 1;
    for(auto &i: g[s])if(!vis[i])dfs(i);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int t,a,b;
        cin >> t >> a >> b;
        if(t == 1){
            auto e = make_pair(a,b);
            for(int i = 0; i < arr.size(); ++i){
                if(check(e,arr[i]))g[i].emplace_back(arr.size());
                if(check(arr[i],e))g[arr.size()].emplace_back(i);
            } 
            arr.emplace_back(e);
        }
        else{
            a--,b--;
            memset(vis,0,sizeof(vis));
            dfs(a);
            if(vis[b])cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}