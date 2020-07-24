#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    int n,m,a,ans=0;
    cin >> n >> m ;
    vector<int> arr(n);
    for(int &i: arr)cin >> i;
    while(m--){
        cin >> a;
        s.emplace(a);
    }
    sort(arr.begin(),arr.end());
    for(int i : arr){
        auto it = s.lower_bound(i);
        if(it == s.end())ans++;
        else s.erase(it);
    }
    cout << ans;
    return 0;
}