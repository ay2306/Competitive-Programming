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
int n;
V<int> adj[510];
char ans[510];

int main(){
    int m;
    cin >> n >> m;
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    loop(i,0,510)ans[i]='f';
    int first_a = 0;
    int first_b = n+1;
    loop(i,0,n){
        if(adj[i].size() == n-1){
            ans[i] = 'b';
            first_b = min(first_b,i);
        }
    }
    if(first_b == n+1){
        first_a = 0;
    }else{
        for(auto i: adj[first_b]){
            if(ans[i] == 'f'){
                first_a = i;
                break;
            }
        }
    }
    ans[first_a] = 'a';
    queue<int> q;
    q.push(first_a);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto i: adj[u]){
            if(ans[i] == 'f'){
                ans[i] = 'a';
                q.push(i);
            }
        }
    }
    loop(i,0,n){
        if(ans[i] == 'f')ans[i] = 'c';
    }
    int cnt[3] = {};
    loop(i,0,n){
        for(auto j: adj[i]){
            if(abs(ans[i]-ans[j]) > 1){
                cout << "No\n";
                return 0;
            }
        }
        cnt[ans[i]-'a']++;
    }
    loop(i,0,n){
        if(ans[i] == 'a' && adj[i].size() != cnt[0]+cnt[1]-1){
            cout << "No\n";
            return 0;
        }
        if(ans[i] == 'b' && adj[i].size() != cnt[0]+cnt[1]+cnt[2]-1){
            cout << "No\n";
            return 0;
        }
        if(ans[i] == 'c' && adj[i].size() != cnt[1]+cnt[2]-1){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n" ; loop(i,0,n)cout << ans[i];
   return 0;
}