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

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll> > arr;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        arr.pb(mp(a,0));
    }
    for(int i = 0; i < n; ++i){
        cin >> arr[i].second;
    }
    priority_queue<PLL,V<PLL>,greater<PLL> > p;
    for(int i = 0; i < n; ++i){
        while(p.size() && arr[i].first >= p.top().first){
            p.pop();
        }
        p.push(arr[i]);
    }
    int k = 0;
    map<ll,ll> ans;
    while(p.size()){
        if(ans[p.top().second] == 0)k++;
        ans[p.top().second]++;
        p.pop();
    }
    cout << k << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}