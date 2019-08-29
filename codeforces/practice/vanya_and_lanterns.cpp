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

int main(){
    int n;
    ll l;
    cin >> n >> l;
    D<ll> v;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        v.pb(a);
    }
    sort(v.begin(),v.end());
    if(v[0] != 0)v.pf(-1*v[0]);
    if(*v.rbegin() != l)v.pb(2*l - (*v.rbegin()));
    ll mx = 0;
    // for(auto it : v){
    //     cout << it << " ";
    // }
    // cout << endl;
    for(int i = 1; i < v.size(); ++i){
        // cout << v[i] << " " << v[i-1] << " " << v[i]-v[i-1] << endl;
        mx = max(v[i]-v[i-1],mx);
    }
    double ans = mx/2.0;
    printf("%.15f",ans);
    return 0;
}