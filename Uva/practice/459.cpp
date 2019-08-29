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
#define MAXN 1001000
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
int n;
char b;
int c = 1;
void dfs(int i){
    if(visited[i])return;
    visited[i] = true;
    for(auto k : adj[i])if(!visited[k])dfs(k);
}

void solve(){
    string a;
    int ans=0;
    // while(b >= 'A' && b <= 'Z')cin >> b;
    if(c++ > 1)cout << "\n";
    n = int(b-'A') + 1;
    // cout << b << " " << n << "\n";
    getline(cin,a);
    adj.assign(n,vector<int>());
    visited.assign(n,false);
    while(1){
        // cin >> a;
        getline(cin,a);
        // cout << a << endl;
        // if(a.length() == 1){b = a[0];break;}
        if(a == "")break;
        adj[int(a[0]-'A')].pb(int(a[1]-'A'));
        adj[int(a[1]-'A')].pb(int(a[0]-'A'));
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans << "\n";
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--){
        cin >> b;
        solve();
    }
    return 0;
}