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
int n;
V<V<int> > adj;
V<int> del;
V<int> cal;
V<int> ans;
V<int> val;

void dfs1(int s = 0, int p =-1){
    for(auto i: adj[s]){
        if(i == p)continue;
        ans[i] = __gcd(val[i],ans[s]);
        dfs1(i,s);
    }
}

void dfs(int s = 0, int dist = 0, int p = -1){
    for(int i = 0; i < del.size(); ++i){
        cal[i] += (val[s] % del[i] == 0);
        if(cal[i] >= dist){
            ans[s] = max(ans[s],del[i]);
        }
    }
    for(auto i: adj[s]){
        if(i == p)continue;
        dfs(i,dist+1,s);
    }
    for(int i = 0; i < del.size(); ++i){
        cal[i] -= (val[s] % del[i] == 0);
    }
}

int main(){
    cin >> n;
    adj = V<V<int> > (n);
    ans = V<int> (n,0);
    val = V<int> (n);
    loop(i,0,n)cin >> val[i];
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ans[0] = 0;
    dfs1();
    ans[0] = val[0];
    for(int i = 1; i*i <= val[0]; ++i){
        if(val[0]%i ==0){
            del.pb(i);
            del.pb(val[0]/i);
            if(i*i == val[0])del.pop_back();
        }
    }
    cal.resize(del.size());
    sort(del.begin(),del.end());
    dfs();
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}