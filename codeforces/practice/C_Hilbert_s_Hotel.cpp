#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<long long> a(n);
        long long x = INT_MAX*1LL*n,cnt = 0;
        for(auto &i: a){
            cnt++;
            scanf("%lld",&i);
            i+=x+cnt;
            i%=n;
        }
        sort(a.begin(),a.end());
        if(unique(a.begin(),a.end()) - a.begin() != n)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}