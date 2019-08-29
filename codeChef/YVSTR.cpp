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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char,ll> > arr;
    arr.push_back(make_pair(s[0],1));
    for(int i = 1; i < n; ++i){
        if(s[i] == arr.rbegin()->first)arr.rbegin()->second++;
        else arr.push_back(make_pair(s[i],1));
    }
    ll ans = 0;
    V<ll> a;
    for(auto i: arr)a.pb(i.second);
    for(int i = 1; i < a.size(); ++i){
        ans = (ans%MOD + ((a[i]%MOD)*(a[i-1]%MOD))%MOD)%MOD;
    }
    for(int i = 0; i < a.size(); ++i)ans = (ans%MOD + a[i]%MOD)%MOD;
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}