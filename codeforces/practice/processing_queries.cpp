//https://codeforces.com/contest/644/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll x,y,n,b,t=0,i = 1;
    scanf("%lld%lld",&n,&b);
    deque<pair<ll,ll>> q;
    vector<ll> ans(n,-1);
    vector<pair<ll,ll>> a(n);
    for(auto& [x,y]: a)scanf("%lld%lld",&x,&y);
    pair<ll,ll> process(a[0].first+a[0].second,0);
    int k = 0;
    while(process.first != LLONG_MAX || !q.empty() || i < n){
        if(t == process.first){
            ans[process.second] = process.first;
            process = make_pair(LLONG_MAX,LLONG_MAX);
        }
        for(; i < n && a[i].first == t; ++i)q.push_back(make_pair(a[i].first+a[i].second,i));
        if(process.first == LLONG_MAX && q.size()){
            process = *q.begin();
            q.pop_front();
        }
        t = process.first;
        if(!q.empty())t = min(t,q.begin()->first);
        else t
        printf("process = (%lld, %lld), time = %lld, q.size() = %d\n",process.first,process.second,t,(int)q.size());
    }
    for(auto &i: ans)printf("%lld ",i);
    return 0;
}