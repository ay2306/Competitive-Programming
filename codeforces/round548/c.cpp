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
    }else{
        parent[pb] = pa;
        Rank[pa]+=((Rank[pa]==Rank[pb])?1:0);
    }
}

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n/2);
    p = (p%MOD * p%MOD)%MOD;
    if(n%2)p = (a%MOD * p%MOD)%MOD;
    return p;
}

int main(){
    ll n,k;
    cin >> n >> k;
    parent=V<int>(n);
    Rank=V<int>(n,0);
    loop(i,0,n)parent[i] = i;
    loop(i,0,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        if(c == 0){
            a--;
            b--;
            UNION(a,b);
        }
    }
    ll ans = power(n,k);
    unordered_map<ll,ll> m;
    loop(i,0,n){
        m[findParent(i)]++;
    }
    // cout << "INIT : " <<  ans << "\n";
    for(auto i: m){
        ll p = i.second;
        ll res = power(p,k);
        // cout << "RES: " << res << " \n";
        ans = (ans - res + MOD)%MOD;
    }
    cout << ans;
    return 0;
}