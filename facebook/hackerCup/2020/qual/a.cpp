#include<bits/stdc++.h>
using namespace std;

void solve(int test){
    int n;
    cin >> n;
    string in,out;
    cin >> in >> out;
    vector<vector<bool>> ans(n,vector<bool> (n,false));
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            ans[i][j] = true;
            if(!(j+1 < n && in[j+1] == 'Y' && out[j] == 'Y'))break;
        }
        for(int j = i; ~j ; --j){
            ans[i][j] = true;
            if(!(j && in[j-1] == 'Y' && out[j] == 'Y'))break;
        }
    }
    cout << "Case #" << test << ":\n";
    for(auto &i: ans){
        for(auto j: i)cout << (j ? "Y" : "N");
        cout << "\n";
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int test = 1; test <= t; ++test){
        solve(test);
    }
    return 0;
}