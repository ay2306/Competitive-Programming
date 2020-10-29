#include<bits/stdc++.h>
#define int long long
#define PQ priority_queue<int,vector<int>>
using namespace std;
const int N = 1e5+110;
vector<pair<int,int>> g[N];
int n,s,lev[N],sub[N],type[N];

int dfs(int s, int p = -1){
    if(p == -1)lev[s] = 1;
    int cnt = 0;
    sub[s] = 0;
    for(auto& [u,w]: g[s]){
        if(u == p)continue;
        lev[u] = lev[s] + 1;
        sub[s]+=dfs(u,s);
        cnt++;
    }
    sub[s] += (cnt == 0);
    return sub[s];
}

signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&s);
        p.clear();
        p.resize(n+1);
        vector<pair<int,pair<int,int>>> e;
        for(int i = 1; i <= n; ++i)g[i].clear();
        for(int i = 1; i < n; ++i){
            int a,b,w;
            scanf("%lld%lld%lld%lld",&a,&b,&w,type+i);
            type[i]--;
            g[a].emplace_back(b,w);
            g[b].emplace_back(a,w);
            e.emplace_back(w,make_pair(a,b));
        }
        int index = 0, sum = 0;
        dfs(1);
        vector<multiset<int>> del(n+1);
        priority_queue<int,vector<int>> p[2];
        for(auto [w,ed]: e){
            PQ p1;
            int a = ed.first;
            int b = ed.second;
            if(lev[a] > lev[b])swap(a,b);
            sum+=w*sub[b];
            while(w){
                p[type[index]].emplace((w - w/2) * sub[b]);
                w/=2;
            }
            index++;
        }
        int target = sum - s;
        int ans = 0;
        if(target <= 0){
            printf("%lld\n",ans);
            continue;
        }
        sum  = 0;
        int res = 0;
        multiset<int> avail;
        printf("target = %lld\n",target);
        while(p[1].size() && sum < target){
            res+=2;
            sum+=p[1].top().top();
            auto p2 = p[1].top();
            printf(" 2 impact = %lld, sum = %lld, res = %lld\n",p[1].top(),sum,res);
            avail.emplace(p[1].top());
            p[1].pop();
        }
        ans = LLONG_MAX;
        if(sum >= target)ans = res;
        while(p[0].size()){
            res++;
            sum+=p[0].top();
            printf(" 1 impact = %lld, sum = %lld, res = %lld\n",p[0].top(),sum,res);
            while(avail.size() && sum - (*avail.begin()) >= target){
                res-=2;
                sum -= (*avail.begin());
                printf(" DEL impact = %lld, sum = %lld, res = %lld\n",*avail.begin(),sum,res);
                avail.erase(avail.begin());
            }
            if(sum >= target)ans = min(ans,res);
            p[0].pop();
        }
        printf("%lld\n",ans);
    }   
    return 0;
}