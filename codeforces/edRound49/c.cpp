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
// #define MAXN 25
using namespace std;
const int maxn = 1e4+10;
void solve(){
    // map<ll,ll> m;
    int n;
    cin >> n;
    int m[maxn] = {0};
    V<ll> v;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        if(m[a] == 1 || m[a] == 3)v.pb(a);
        m[a]++;
    }
    sort(v.begin(),v.end());
    // double mn = 1000000000;
    double ans1 = v[1];
    double ans2 = v[0];
    double mn = ((ans1*ans1)+(ans2*ans2))/(ans1*ans2);
    for(int i = 1; i+1 < v.size(); ++i){
        double a = v[i];
        double b = v[i+1];
        a = ((a*a)+(b*b))/(a*b);
        if(a < mn){
            mn = a;
            ans1 = v[i];
            ans2 = v[i+1];
        }
    }
    ll a = ans1;
    ll b = ans2;
    cout << a << " " << a << " " << b << " " << b;
    // cout << " " << mn;
    cout  << "\n";
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}