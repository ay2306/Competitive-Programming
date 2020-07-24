//https://codeforces.com/contest/547/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int pr[N],f[N],arr[N],n,q,a,A,inc[N],ch;
long long ans;


int main(){
    auto clk = clock();
    for(int i = 2; i < N; ++i){
        if(!pr[i])for(int j = i; j < N; j+=i)pr[j] = i;
    }
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    while(q--){
        scanf("%d",&a);
        if(inc[a])ch=-1;
        else ch = 1;
        inc[a]^=1;
        a = arr[a], A = a;
        vector<int> p;
        while(A > 1){
            p.emplace_back(pr[A]);
            while(A%p.back() == 0)A/=p.back();
        }
        n = p.size();
        long long matched = 0;
        for(int mask = 0; mask < (1 << n); ++mask){
            int number = 1;
            for(int i = 0 ; i < n; ++i)if((mask >> i) & 1)number*=p[i];
            if(ch == -1)f[number]--;
            if(__builtin_popcount(mask) & 1)matched-=f[number];
            else matched += f[number];
            if(ch == 1)f[number]++;
        }
        ans+=(ch*1LL*matched);
        printf("%lld\n",ans);
    }
    #ifdef LOCAL
        printf("TIME ELAPSED : %.3Lf ms\n",double(clk-clock())/CLOCKS_PER_SEC);
    #endif
    return 0;
}