//https://codeforces.com/contest/55
#pragma GCC optimize("O3")
// #pragma GCC optimize("O2")
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<cstring>
#include<stdio.h>
using namespace std;

#define ll long long int
int num[20],sz;
const int bigMod = 9*8*7*5;
ll dp[19][1<<8][bigMod+5];
//pos, mask, multiplier, match, 7 included or not
int all_mod[bigMod][10];
ll power[20],rem[11*bigMod];
int current;
ll cal(int pos = 0, int mask = 0, int modular = 0, int f = 0){
    if(pos == -1){
        for(int i = 0; i < 8; ++i)
            if(((mask>>i)&1) && all_mod[modular][i+2])return 0;
        return 1;
    }
    ll &res = dp[pos][mask][modular];
    if(f && ~res)return res;
    int lst = 9;
    if(!f)lst=num[pos];
    long long tot = 0;
    for(int i = 0; i <= lst; ++i){
        if(i < 2)tot+=cal(pos-1,mask,rem[modular*10+i],(f || i != lst));
        else tot+=cal(pos-1,(mask|(1<<(i-2))),rem[modular*10+i],(f || i != lst));
    }
    if(f)res = tot;
    return tot;
}

void solve(){
    ll l,r;
    cin >> l >> r;
    sz = 0;
    while(r){
        num[sz++] = r % 10;
        r/=10;
    }
    // reverse(num,num+sz);
    ll s1 = cal(sz-1);
    l--;
    sz = 0;
    while(l){
        num[sz++] = l % 10;
        l/=10;
    }
    // reverse(num,num+sz);
    // memset(dp,-1,sizeof(dp));
    ll s2 = cal(sz-1);
    // cout << s1  << " " << s2 << "\n";
    cout << s1-s2 << "\n";
}

int main(){
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef ay2306
        auto clk = std::chrono::high_resolution_clock::now();
    #endif
    power[0] = 1;
    for(int i = 1; i < 20; ++i)power[i] = (power[i-1]*10)%bigMod;
    for(int i = 0; i < 11*bigMod; ++i)rem[i] = i%bigMod;
    for(int i = 0; i < bigMod; ++i)
        for(int j = 2; j < 10; ++j)
            all_mod[i][j] = i%j;
    int t;
    cin >> t;
    while(t--)solve();
    #ifdef ay2306
        auto clk2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(clk2-clk);
        cout << "\n\n" << time_span.count() << " ms.\n\n"; 
    #endif
    return 0;
}