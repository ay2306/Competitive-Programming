#include<bits/stdc++.h>
using namespace std;

int visited[1000][1000];
int arr[1000][1000];

int n,m;
int g;
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m)return false;
    return true;
}

int dfs(int i, int j){
    if(visited[i][j] != 0)return 0;
    visited[i][j] = 1;
    int ans = 0;
    if(valid(i+1,j) && abs(arr[i][j] - arr[i+1][j]) >= g){
        ans += dfs(i+1,j);
    }
    if(valid(i-1,j) && abs(arr[i][j] - arr[i-1][j]) >= g){
        ans += dfs(i-1,j);
    }
    
    if(valid(i,j-1) && abs(arr[i][j] - arr[i][j-1]) >= g){
        ans += dfs(i,j-1);
    }
    if(valid(i,j+1) && abs(arr[i][j] - arr[i][j+1]) >= g){
        ans += dfs(i,j+1);
    }
    return ans+1;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n >> m;
    g = __gcd(n,m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)cin >> arr[i][j];
    }
    memset(visited,0,sizeof(visited));
    int mx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(visited[i][j] == 0)mx = max(mx,dfs(i,j));
        }
    }
    // cout << n << " " << m << "\n";
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j)cout << arr[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "ANS = \n";
    cout << mx;
    return 0;
}