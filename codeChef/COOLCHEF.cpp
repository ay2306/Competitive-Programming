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
#define all(container) container.begin(),container.end()
#define MAXN 25
using namespace std;

int sz;

struct query{
    int l;
    int r;
    int ind;
    query(int l, int r, int index):l(l),r(r),ind(index){}
    query(){}
};

bool compare(query &a, query &b){
    if(a.l/sz != b.l/sz)return a.l < b.l;
    if((a.l/sz)&1)return a.r < b.r;
    return b.r < a.r;
}

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%MOD;
    ll p = power(a,n/2);
    p*=p;
    p%=MOD;
    if(n%2)p*=a;
    p%=MOD;
    return p;
}

void solve(){
    ll n,q;
    cin >> n >> q;
    vector<ll> fact(n+10,1);
    vector<ll> factInv(n+10,1);
    loop(i,2,n+1){
        fact[i] = (fact[i-1]*i)%MOD;
        factInv[i] = (factInv[i-1]*power(i,MOD-2))%MOD;
    }
    vector<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    sz = sqrt(n);
    ll val = 1;
    unordered_map<int,int> m;
    int start = 1;
    int end = 0;
    V<query> queries;
    loop(i,0,q){
        int l,r;
        cin >> l >> r;
        queries.pb(query(l-1,r-1,i));
    }
    sort(all(queries),compare);
    V<ll> ans(q);
    loop(i,0,q){
        int L = queries[i].l;
        int R = queries[i].r;
        while(start < L){
            val*=fact[m[arr[start]]];
            val%=MOD;
            m[arr[start]]--;
            val*=factInv[m[arr[start]]];
            val%=MOD;
            start++;
        }
        while(start > L){
            start--;
            val*=fact[m[arr[start]]];
            val%=MOD;
            m[arr[start]]++;
            val*=factInv[m[arr[start]]];
            val%=MOD;
        }
        while(end < L){
            end++;
            val*=fact[m[arr[end]]];
            val%=MOD;
            m[arr[end]]++;
            val*=factInv[m[arr[end]]];
            val%=MOD;
        }
        while(start > L){
            val*=fact[m[arr[end]]];
            val%=MOD;
            m[arr[end]]--;
            val*=factInv[m[arr[end]]];
            val%=MOD;
            end--;
        }
        ans[queries[i].ind] = (val*fact[R-L+1])%MOD;
    }
    loop(i,0,n){
        cout << ans[i] << "\n";
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}