#include<bits/stdc++.h>
using namespace std;

int main(){
    int p,q,l,r;
    cin >> p >> q >> l >> r;
    vector<int> a,b;
    while(p--){
        int x,y;
        cin >> x >> y;
        while(x <= y)a.emplace_back(x++);
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        while(x <= y)b.emplace_back(x++);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    b.resize(unique(b.begin(),b.end())-b.begin());
    a.resize(unique(a.begin(),a.end())-a.begin());
    int ans = 0;
    while(l <= r){
        for(auto &i: b)i+=l;
        for(int &i : b){
            if(binary_search(a.begin(),a.end(),i)){
                ans++;break;
            }
        }
        for(auto &i: b)i-=l;
        l++;
    }
    cout << ans ;
}