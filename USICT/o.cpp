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
#define MAXN 25
using namespace std;

ll arr[10000];

void solve(){
    map<int,ll> m;
    int n;
    ll ans = 0
    cin >> n;
    loop(i,0,n){
        int a;
        cin >> a;
        if(arr[a] == 0)m[a]++;
    }
    ans = 0;
    for(auto i: m){
        ll t = (i.second/2 +1)
        for(auto j : m){
            if(i == j)continue;
            t  = (t%MOD * (i.second%MOD))%MOD;
        } 
        ans = (ans%MOD+t%MOD)%MOD;
    }
    cout << ans
}

int main(){
    for(int i = 2; i < 10000; ++i){
        if(arr[i] == 0){
            for(int j = 2; i*j < 10000; ++j)arr[i*j]++;
        }
    }
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}