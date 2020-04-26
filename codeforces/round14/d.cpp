#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define V vector
#define P pair
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define C continue;
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define ld long double
#define xx first
#define yy second
#define fst ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 1e9;
const int mod = 1e9+7;
const int N = 250;
int n,a,b;
set<int> g[N];
int lev[N],ans;
int dfs(int s, int p=-1){
    int mx = s;
    if(p == -1)lev[s] = 0;
    else lev[s] = lev[p]+1;
    for(auto &i: g[s]){
        if(i==p)continue;
        int k = dfs(i,s);
        if(lev[k] > lev[mx])mx = k;
    }
    return mx;
}

int main(){
    scanf("%d",&n);
    loop(i,1,n){
        scanf("%d%d",&a,&b);
        g[a].insert(b);
        g[b].insert(a);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            if(g[i].count(j) == 0)continue;
            g[i].erase(j);
            g[j].erase(i);
            lev[i] = 0;
            lev[j] = 0;
            int d1 = lev[dfs(dfs(i))];
            int d2 = lev[dfs(dfs(j))];
            // printf("i = %d, j = %d , d1 = %d, d2 = %d\n",i,j,d1,d2);
            g[i].insert(j);
            g[j].insert(i);
            ans = max(ans,d1*d2);
        }
    }
    return printf("%d",ans),0;
}