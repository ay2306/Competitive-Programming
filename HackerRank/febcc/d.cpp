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
#define MAXN 25
using namespace std;

V<ll> arr;
ll check(){
    ll k = 1;
    ll sum = 0;
    for(auto i: arr){
        sum+=(i/k);
        k*=2;
    }
    return sum;
}

void solve(){
    ll n;
    cin >> n;
    arr = V<ll> (n);
    loop(i,0,n)cin >> arr[i];
    sort(arr.begin(),arr.end());
    V<ll> res;
    do{
        res.pb(check());
    }while(next_permutation(arr.begin(),arr.end()));
    int q;
    cin >> q;
    sort(res.begin(),res.end());
    // for(auto i: res)cout << i << " ";
    // cout << endl;
    while(q--){
        ll a;
        cin >> a;
        ll ind = lower_bound(res.begin(),res.end(),a) - res.begin();
        cout << res.size()-ind << " ";
    }
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}