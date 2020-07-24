//https://codeforces.com/contest/489/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; ++i)cin >> a[i];
    for(int i = 0; i < n-1; ++i){
        int mni = i;
        for(int j = i+1; j < n; ++j){
            if(a[j] < a[mni])mni=j;
        }
        if(mni != i)ans.emplace_back(i,mni);
        swap(a[i],a[mni]);
    }
    cout << ans.size() << "\n";
    for(auto& [x,y]: ans)cout << x << " " << y << "\n";
    return 0;
}