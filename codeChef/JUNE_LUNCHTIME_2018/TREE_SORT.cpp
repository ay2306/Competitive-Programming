/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
const int MAX = 2e5 + 5;
int n;
PII vals[MAX];
bool is_root[MAX];
V<int> g[MAX];

bool intersect(PII a, PII b){
    if(a.S < b.F || a.F > b.S){
        return false;
    }
    return true;
}

int dfs(int root){
    // cout << "ROOT = " << root << endl;
    if(g[root].size() == 0)return 0;
    int l = dfs(g[root][0]);
    int r = dfs(g[root][1]);
    if(l == -1 || r == -1){
        return -1;
    }
    if(intersect(vals[g[root][0]],vals[g[root][1]])){
        return -1;
    }
    vals[root].first = min(vals[g[root][0]].first,vals[g[root][1]].first);
    vals[root].second = max(vals[g[root][0]].second,vals[g[root][1]].second);
    if(vals[g[root][0]].first < vals[g[root][1]].first){
        return l+r;
    }else{
        return l+r+1;
    }
}

int main(){
    // FILE_READ
    int t,l,r;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            g[i].clear();
            is_root[i] = true;
            vals[i] = mp(MAX,0);
        }
        for(int i = 1; i <= n; ++i){
            cin >> l >> r;
            if(l == -1){
                vals[i] = mp(r,r);
            }else{
                g[i].pb(l);
                g[i].pb(r);
                is_root[l] = false;
                is_root[r] = false;
            }
        }
        int root = 0;
        for(int i = 1; i <= n; ++i){
            if(is_root[i]){
                root = i;
                // cout << i << " ";
            }
        }
        // cout << endl;
        int ans = dfs(root);
        cout << ans << endl;
    }
    return 0;
}