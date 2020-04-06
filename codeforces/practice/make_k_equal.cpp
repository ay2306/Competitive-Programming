//https://codeforces.com/contest/1328/problem/F
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<ll> a(n),pref(n,0),suff(n,0);
    for(auto &i: a)scanf("%lld",&i);
    sort(a.begin(), a.end());
    for(int i = k-1; i < n; ++i){
        if(a[i] == a[i-k+1]){
            printf("0");
            return 0;
        }
    }
    pref[0] = a[0];
    unordered_map<int,int> f,l;
    suff[n-1] = a[n-1];
    for(int i = 1; i < n; ++i)pref[i]=pref[i-1]+a[i],suff[n-1-i]=suff[n-i]+a[n-i-1];
    for(int i = 1; i < n; ++i){l[a[i]]=max(l[a[i]],i);if(f.find(a[i]) == f.end())f[a[i]]=i;}
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        ll pref_count = f[a[i]];
        ll frq = l[a[i]]-f[a[i]]+1;
        if(pref_count+frq < k)continue;
        ll extra = k - frq;
        ll sum = pref[f[a[i]]-1];
        ll steps = a[i]*pref_count-sum;
        steps-=(pref_count-extra);
        ans = min(ans,steps);
    }
    for(int i = n-1; i >= 0; i--){
        ll suff_count = n-1-l[a[i]];
        ll frq = l[a[i]]-f[a[i]]+1;
        if(suff_count+frq < k)continue;
        ll extra = k - frq;
        ll sum = suff[l[a[i]]+1];
        ll steps = sum - a[i]*suff_count;
        steps-=(suff_count-extra);
        ans = min(ans,steps);
    }
    for(int i = 0; i < n; ++i){
        ll suff_count = n-1-l[a[i]];
        ll frq = l[a[i]]-f[a[i]]+1;
        ll extra = k - frq;
        ll sum = 0;
        if(suff_count)sum += suff[l[a[i]]+1];
        ll steps = sum - a[i]*suff_count;
        ll pref_count = f[a[i]];
        sum = 0;
        if(pref_count)sum += pref[f[a[i]]-1];
        steps += a[i]*pref_count-sum;
        steps-=(pref_count+suff_count-extra);
        ans = min(ans,steps);

    }
    printf("%lld\n",ans);
}