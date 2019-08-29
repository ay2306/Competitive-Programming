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

const ll maxn = 2e5 + 10;
set<int> s;
set<int> g[maxn];
int sz = 0;

void dfs(int u){
    V<int> next;
    sz++;
    s.erase(u);
    for(auto i: s){
        if(g[u].find(i) == g[u].end()){
            next.pb(i);
        }
    }
    for(auto i: next){
        s.erase(i);
    }
    for(auto i: next){
        dfs(i);
    }
}

int main(){
    int n ,k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)s.insert(i);
    while(k--){
        int a ,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    V<int> ans;
    while(s.size()){
        sz = 0;
        int val = *s.begin();
        s.erase(s.begin());
        dfs(val);
        ans.pb(sz);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(),ans.end());
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}