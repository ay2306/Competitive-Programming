#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5+10;

int val[N],dp1[N][20], dp2[N][20], lev1[N], lev2[N], mx[N][20], sum[N][20];

void addReal(int u, int p){
    dp1[u][0] = p;
    mx[u][0] = val[p];
    lev1[u] = lev1[p] + 1;
    for(int i = 1; i < 20; ++i){
        dp1[u][i] = dp1[dp1[u][i-1]][i-1]; 
        mx[u][i] = max(mx[dp1[u][i-1]][i-1],mx[u][i-1]); 
    }
}

void addSeq(int u, int p){
    dp2[u][0] = p;
    sum[u][0] = val[p];
    lev2[u] = lev2[p] + 1;
    for(int i = 1; i < 20; ++i){
        dp2[u][i] = dp2[dp2[u][i-1]][i-1]; 
        sum[u][i] = sum[dp2[u][i-1]][i-1]+sum[u][i-1]; 
    }
}

pair<int,int> getKthReal(int x, int k){
    int mx = -1;
    for(int i = 0; i < 20; ++i){
        if((k >> i) & 1){
            mx = max(::mx[x][i],mx);
            x = dp1[x][i];
        }
    }
    return pair<int,int> (x, mx);
}

pair<int,int> getKthSeq(int x, int k){
    int sum = 0;
    for(int i = 0; i < 20; ++i){
        if((k >> i) & 1){
            sum += ::sum[x][i];
            x = dp2[x][i];
        }
    }
    return pair<int,int> (x, sum);
}

signed main(){
    int last = 0,n,p,q,t,cnt = 1;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld%lld%lld",&t,&p,&q);
        if(t == 1){
            cnt++;
            int r = p ^ last;
            int w = q ^ last;
            val[cnt] = w;
            addReal(cnt,r);
            int lo = 1, hi = lev1[cnt], ans = -1;
            while(lo <= hi){
                int mx,par,mid = lo + hi >> 1;
                tie(par,mx) = getKthReal(cnt,mid);
                if(mx >= w)hi = mid-1,ans = mid;
                else lo = mid+1;
            }  
            if(~ans)addSeq(cnt,ans);
        }
        else{
            int r = p ^ last;
            int x = q ^ last;
            if(val[r] < x){
                printf("0\n");
                continue;
            }
            x-=val[r];
            int ans = 0, lo = 1, hi = lev2[r];
            while(lo <= hi){
                int sum,par,mid = lo + hi >> 1;
                tie(par,sum) = getKthSeq(cnt,mid);
                if(sum <= x)lo = mid+1,ans = mid;
                else hi = mid-1;
            }  
            ans++;
            last
            printf("%lld\n",ans);
        }
    }
    return 0;
}