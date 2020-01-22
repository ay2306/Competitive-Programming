#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
unordered_map<int,int> m[10];
int a[10][1010];
V<int> adj[1010];
int lev[1010];
int in[1010];
int n,k;
int dis(){
    loop(i,1,n+1){
        for(auto j: adj[i])in[j]++;
    }
    queue<int> q;
    loop(i,1,n+1){
        if(in[i] == 0)q.push(i);
    }
    int mx = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto i: adj[u]){
            lev[i] = lev[u]+1;
            mx=max(lev[i],mx);
            in[i]--;
            if(in[i] == 0)q.push(i);
        }
    }
    return mx+1;
}
int main(){
    cin >> n >> k;
    loop(i,0,k){
        loop(j,0,n){
            cin >> a[i][j];
            m[i][a[i][j]]=j;
        }
    }
    loop(i,1,n+1){
        loop(j,1,n+1){
            if(i == j)continue;
            bool pos = true;
            loop(o,0,k){
                pos&=(m[o][i] < m[o][j]);
            }
            if(pos){
                // printf("ADDING %d -> %d\n",i,j);
                adj[i].pb(j);
            }
        }
    }
    cout << dis();
   return 0;
}