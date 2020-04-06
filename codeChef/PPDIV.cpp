#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int ans=0,n,a,i,j,k;
        scanf("%lld",&n);
        unordered_set<long long int> s;
        ans=n%mod;
        for(i = 2; i*i <= n+100 && i <= n && i < (int)1e6+100; ++i){
            j = i*i;
            while(j <= n){
                if(s.find(j) == s.end()){
                    ans = (ans + (n/j)*j)%mod;
                    s.insert(j);
                }
                j*=i;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}