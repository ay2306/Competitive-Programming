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
V<bool> vis;
unordered_map<ll,int> m;
unordered_map<int,ll> m1;
void dfs(int i){
    cout << m1[i] << " ";
    vis[i] = true;
    for(auto k: adj[i]){
        if(!vis[k]){
            dfs(k);
        }
    } 
}
int main(){
    cin >> n;
    V<ll> arr(n);
    loop(i,0,n){cin >> arr[i];m[arr[i]] = i;m1[i] = arr[i];}
    adj = V<V<int> > (n,V<int> ());
    vis = V<bool> (n,false);
    loop(i,0,n){
        if(m.find(arr[i]*2) != m.end()){
            adj[i].pb(m[arr[i]*2]);
        }
        if(m.find(arr[i]/3) != m.end() && arr[i]%3 == 0){
            adj[i].pb(m[arr[i]/3]);
        }
    }
    V<int> in(n,0);
    for(auto i: adj){
        for(auto j: i)in[j]++;
    }
    dfs(min_element(in.begin(),in.end()) - in.begin());
    return 0;
}