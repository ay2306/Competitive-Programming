#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll x,y,n,b,t=0,i;
    scanf("%lld%lld",&n,&b);
    queue<pair<ll,ll>> q;
    vector<ll> ans(n,-1);
    pair<ll,ll> process(-1,-1);
    vector<pair<ll,ll>> a(n);
    for(auto& [x,y]: a)scanf("%lld%lld",&x,&y);
    while(i<n || process.first != -1){
        if(process.second == t || process.first == -1){
            if(process.first != -1)ans[process.second] = t;
            if(q.size()){
                process = q.front();
                q.pop();
            }
        }
        while(i < n && a[i].first <= process.first){
            
        }
    }

    return 0;
}