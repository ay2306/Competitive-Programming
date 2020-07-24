#include<bits/stdc++.h>
#define int long long
using namespace std;

int cur;

bool compare(pair<int,int> a, pair<int,int> b){
    return (a.first * (1LL << (cur-a.second))) <= (b.first * (1LL << (cur-b.second)));
}

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        cur = 0;
        int a,n,x;
        scanf("%lld%lld",&n,&x);
        priority_queue<pair<int,int>,vector<pair<int,int>>,function<bool(pair<int,int>,pair<int,int>)>> p(compare);
        for(int i = 0; i < n; ++i){
            scanf("%lld",&a);
            p.emplace(a,0);
        }
        while(p.size()){
            auto y = p.top();
            p.pop();
            // printf("%lld %lld\n",y.first,y.second);
            int val =  y.first;
            val *= (1 << (cur-y.second));
            val = max(0LL,(val-x)<<1);
            cur++;
            x*=2;
            if(val)p.emplace(val,cur);
        }
        printf("%lld\n",cur);
    }
    return 0;
}