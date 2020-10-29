#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y,a;
    scanf("%d%d%d",&n,&x,&y);
    vector<int> arr(n+1);
    vector<vector<int>> f(n+2);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a);
        arr[i] = a;
        f[a].emplace_back(i);
    }
    if(x > y || y > n)return void(printf("NO\n"));
    vector<int> ans(n+1);
    for(int i = 1; i <= n+1; ++i){
        if(!f[i].size()){
            fill(ans.begin(),ans.end(),i);
            break;
        }
    }
    set<pair<int,int>> s;
    for(int i = 1; i <= n+1; ++i)
        s.emplace(f[i].size(),i);
    while(x--){
        int col = s.rbegin()->second;
        ans[f[col].back()] = col;
        f[col].pop_back();
        s.erase(prev(s.end()));
        s.emplace(f[col].size(),col);
        y--;
    }
    vector<int> every;
    int mx = s.rbegin()->second;
    for(int &i: f[mx])every.emplace_back(i);
    int z = every.size();
    for(int i = 1; i <= n+1; ++i){
        if(i == mx)continue;
        for(int &j: f[i])every.emplace_back(j);
    }
    for(int i = 0; i < every.size() && y; ++i){
        int p = (i+z)%every.size();
        if(arr[every[p]] != arr[every[i]]){
            y--;
            ans[every[i]] = arr[every[p]];
        }
    }
    if(y)return void(printf("NO\n"));
    printf("YES\n");
    for(int i = 1; i <= n; ++i)printf("%d ",ans[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}