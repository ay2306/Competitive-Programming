#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
ll f[50];
ll x,cnt,ans,c,t;
void cal(ll cur, ll divisors = 1, int pos = 0, ll mx = 60){
    if(divisors > cnt)cnt = divisors,ans=cur;
    else if (divisors == cnt)ans = min(cur,ans);
    if(pos == a.size())return;
    for(int i = 1; i <= mx && cur <= x/a[pos]; ++i){
        cur*=a[pos];
        cal(cur,divisors*(i+1),pos+1,i);
    }
}

int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&x);
        cnt = 1,ans = 1,c=1;
        cal(1);
        printf("%lld %lld\n",ans,cnt);
    }
    return 0;
}