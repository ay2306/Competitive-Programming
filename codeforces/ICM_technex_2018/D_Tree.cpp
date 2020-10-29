#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+10;

long long val[N];

class binaryLifting{
    int mx[N][20],dp[N][20];
    int lev[N];
public:
    binaryLifting(){
        memset(mx,0,sizeof(mx));
        memset(dp,0,sizeof(dp));
        memset(lev,0,sizeof(lev));
    }
    void addNode(int u, int p){
        lev[u] = lev[p] + 1;
        dp[u][0] = p;
        mx[u][0] = val[p];
        for(int j = 1; j < 20; ++j){
            dp[u][j] = dp[dp[u][j-1]][j-1];
            mx[u][j] = max(mx[dp[u][j-1]][j-1],mx[u][j-1]);
        }
    }
    inline int getLevel(int x){
        return lev[x];
    }
    tuple<int,long long,int> getKth(int x, int k){
        int s = 0, m = 0, p = 0;
        for(int i = 0; i < 20; ++i){
            if( k >> i & 1 ){
                m = max(m, mx[x][i]);
                x = dp[x][i];
            }
        }  
        return tuple<int,long long,int>(x,s,m);
    }  
};
class binaryLifting2{
    int dp[N][20];
    long long sum[N][20];
    int lev[N];
public:
    binaryLifting2(){
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        memset(lev,0,sizeof(lev));
    }
    void addNode(int u, int p){
        lev[u] = lev[p] + 1;
        dp[u][0] = p;
        sum[u][0] = val[p];
        for(int j = 1; j < 20; ++j){
            dp[u][j] = dp[dp[u][j-1]][j-1];
            sum[u][j] = sum[dp[u][j-1]][j-1] + sum[u][j-1]; 
        }
    }
    inline int getLevel(int x){
        return lev[x];
    }
    tuple<int,long long,int> getKth(int x, int k){
        long long s = 0, m = 0, p = 0;
        for(int i = 0; i < 20; ++i){
            if( k >> i & 1 ){
                s += sum[x][i];
                x = dp[x][i];
            }
        }  
        return tuple<int,long long,int>(x,s,m);
    }  
};


int32_t main(){
    binaryLifting2 seqTree;
    binaryLifting realTree;
    int n;
    long long last = 0,cnt = 1;
    scanf("%d",&n);
    auto getsum = [](tuple<int,long long,int> a)->long long{
        return get<1>(a);
    };
    auto getdp = [](tuple<int,long long,int> a)->int{
        return get<0>(a);
    };
    auto getmax = [](tuple<int,long long,int> a)->int{
        return get<2>(a);
    };
    while(n--){
        long long p,q,t;
        scanf("%lld%lld%lld",&t,&p,&q);
        if(t == 1){
            int r = p ^ last;
            int w = q ^ last;
            cnt++;
            val[cnt] = w;
            // printf("Adding node %lld to node %lld with weight %lld\n",cnt,r,w);
            realTree.addNode(cnt,r);
            int ans = 1, lo = 1, hi = realTree.getLevel(cnt);
            while(lo <= hi){
                int mid = lo + hi >> 1;
                auto k = realTree.getKth(cnt,mid);
                int mx = getmax(k);
                if(mx >= w)ans = getdp(k), hi = mid-1;
                else lo = mid+1;
            } 
            // printf("Seq Adding node %lld to node %lld with weight %lld\n",cnt,ans,w);
            seqTree.addNode(cnt,ans);
        }else{
            int r = p ^ last;
            long long x = q ^ last;
            // printf("Asking from node %lld with sum = %lld\n",r,x);
            if(x < val[r]){
                cout << "0\n";
                continue;
            }
            x-=val[r];
            int ans = 0;
            int lo = 1, hi = seqTree.getLevel(r);
            while(lo <= hi){
                int mid = lo + hi >> 1;
                auto k = seqTree.getKth(r,mid);
                if(getsum(k) <= x){
                    // cout << getdp(k) << " ";
                    lo = mid+1,ans = mid;
                }
                else hi = mid-1;
            } 
            // cout << ans << " " << getdp(seqTree.getKth(r,ans)) << "\n";
            if(ans == seqTree.getLevel(r) && val[getdp(seqTree.getKth(r,ans-1))] != 0)ans--;
            ans++;
            last = ans;
            printf("%d\n",ans);
        }
    }
    return 0;
}