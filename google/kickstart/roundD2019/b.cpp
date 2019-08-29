#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define V vector
#define mp make_pair
using namespace std;
const ll inf = 1e9+10;
void solve(int test){
    ll n,g,m;
    scanf("%lld %lld %lld",&n,&g,&m);
    unordered_map<ll,V<ll>> cm,ccm;
    unordered_map<ll,ll> rem;
    unordered_map<ll,ll> rem1;
    vector<ll> init(g);
    vector<pair<ll,ll>> c,cc;
    for(ll i = 0; i < g; ++i){
        ll a;
        char d;
        scanf("%lld %c",&a,&d);
        a %= n;
        if(d == 'C'){
            if(cm[a].size() == 0){
                ll temp = (a + m)%n;
                c.push_back(make_pair(temp,i));
            }
            cm[a].push_back(i);
        }else{
            if(ccm[a].size() == 0){
                ll temp = (a + 3*inf*n - m)%n;
                cc.push_back(make_pair(temp,i));
            }
            ccm[a].push_back(i);
        }
        init[i] = a;
    }
    sort(c.begin(),c.end());
    sort(cc.begin(),cc.end());
    for(ll i = 0; i < n; ++i){
        ll cdis = inf;
        ll ccdis = inf;
        if(c.size()){
            auto l = lower_bound(c.begin(),c.end(),mp(i,-1LL));
            if(l == c.end()){
                l = c.begin();
                cdis = l->first - i + n;
            }else{
                cdis = l->first - i;
            }
        }
        if(cc.size()){
            auto l = upper_bound(cc.begin(),cc.end(),mp(i,-1LL));
            if(l == cc.begin()){
                ccdis = i + (n-c.rbegin()->first);
            }else{
                l--;
                ccdis = i-l->first;
            }
        }
        if(ccdis < cdis){
            auto l = upper_bound(cc.begin(),cc.end(),mp(i,-1LL));
            if(l == cc.begin()){
                rem[init[cc.rbegin()->second]]++;
                l = cc.end();
                l--;
                printf("%lld is visited by %lld anti-clockwise\n",i,init[l->second]);
                // ccdis = i + (n-c.rbegin()->first);
            }else{
                l--;
                rem[init[l->second]]++;
                printf("%lld is visited by %lld anti-clockwise\n",i,init[l->second]);
                // ccdis = i-l->first;
            }
        }else if(ccdis > cdis){
            auto l = lower_bound(c.begin(),c.end(),mp(i,-1LL));
            if(l == c.end()){
                l = c.begin();
                rem1[init[l->second]]++;
                printf("%lld is visited by %lld clockwise\n",i,init[l->second]);
                // cdis = l->first - i + n;
            }else{
                rem1[init[l->second]]++;
                printf("%lld is visited by %lld clockwise\n",i,init[l->second]);
                // cdis = l->first - i;
            }
        }else{
            auto l = lower_bound(c.begin(),c.end(),mp(i,-1LL));
            if(l == c.end()){
                l = c.begin();
                rem1[init[l->second]]++;
                printf("%lld is visited by %lld clockwise\n",i,init[l->second]);
            }else{
                rem1[init[l->second]]++;
                printf("%lld is visited by %lld clockwise\n",i,init[l->second]);
            }
            auto l1 = upper_bound(cc.begin(),cc.end(),mp(i,-1LL));
            if(l1 == cc.begin()){
                rem[init[c.rbegin()->second]]++;
                l1 = cc.end();
                l1--;
                printf("%lld is visited by %lld anti-clockwise\n",i,init[l1->second]);
            }else{
                l1--;
                rem[init[l1->second]]++;
                printf("%lld is visited by %lld anti-clockwise\n",i,init[l1->second]);
            }
        }
    }
    vector<int> ans(g,0);
    for(auto i: rem){
        for(auto j: cm[i.first]){
            ans[j] += i.second;
        }
    }
    for(auto i: rem1){
        for(auto j: ccm[i.first]){
            ans[j] += i.second;
        }
    }
    printf("Case #%d: ",test);
    for(auto i: ans){
        printf("%d ",i);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1; i <= t; ++i){
        solve(i);
    }
    return 0;
}