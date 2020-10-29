#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cnt=0;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &i : a)cin >> i;
    map<int,vector<int>> row,col;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == '*')row[i].emplace_back(j),col[j].emplace_back(i);
            cnt+=(a[i][j] == '*');
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int k = row[i].size() + col[j].size() - (a[i][j] == '*');
            if(k == cnt){
                return cout << "YES\n" << i+1 << " " << j+1,0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}