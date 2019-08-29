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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 1e5;
int n,m;
V<V<int> > adj;
V<int> parent;
V<int> Rank;

int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void UNION(int a, int b){
    int pa = findParent(a);
    int pb = findParent(b);
    if(Rank[pa] < Rank[pb]){
        parent[pa] = pb;
    }else if(Rank[pb] < Rank[pa]){
        parent[pb] = pa;
    }else{
        parent[pb] = pa;
        Rank[pa]++;
    }
}
int main(){
    cin >> n >> m;
    adj = V<V<int> > (n,V<int>());
    parent = V<int> (n,0);
    Rank = V<int> (n,0);
    for(int i = 0; i < n; ++i)parent[i] = i;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    int mx = 0;
    int mxi = 0;
    for(int i = 0; i < n; ++i){
        if(mx < adj[i].size()){
            mx = adj[i].size();
            mxi = i;
        }
    }
    V<PII> ans;
    queue<int> s;
    s.push(mxi);
    // cout << "MXI = " << mxi+1 << "\n";
    int ct = 0;
    while(ans.size() < n-1){
        int u = s.front();
        s.pop();
        // cout << u+1 << "\n";
        for(auto i: adj[u]){
            // cout << u+1 << " " << i+1 << "\n";
            if(findParent(u) != findParent(i)){
                UNION(u,i);
                ans.pb(mp(u,i));
                s.push(i);
            }
        }
    }
    for(auto i: ans){
        cout << i.F+1 << " " << i.S+1 << "\n";
    }
    return 0;
}