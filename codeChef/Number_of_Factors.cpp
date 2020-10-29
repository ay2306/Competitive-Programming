#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int t,a,n,p[N];
int main(){
    for(int i = 2; i < N; ++i)
        if(!p[i])
            for(int j = i; j < N; j+=i)p[j] = i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        map<int,int> m;
        while(n--){
            scanf("%d",&a);
            while(a > 1){
                m[p[a]]++;
                a/=p[a];
            }
        }
        long long ans = 1;
        for(auto i: m)ans*=(i.second+1);
        printf("%lld\n",ans);
    }
    return 0;
}