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
    ll n,m,k,l;
    ll ki = 0;
    cin >> n >> m >> k >> l;
    // ll current_min = (m+1)*l;
    ll last_free = LONG_LONG_MAX;
    ll ans = 0;
    ll *arr = new ll[n];
    loop(i,0,n)cin >> arr[i];
    sort(arr,arr+n);
    if(m == 0 && n == 0){
        cout << "0\n";
        return;
    }
    if(n == 0){
        cout << k << "\n";
        return;
    }
    if(k > arr[n-1]){
        ll t = (m+1+n)*l;
        if(k >= t){
            last_free = 0;
            ans = 0;
        }else{
            ll wait = t-k;
            if(wait < last_free){
                ans = wait;
                last_free = wait;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        ll t = (m+1+i)*l;
        if(arr[i] >= k){
            if(k >= t){
                last_free = 0;
                ans = 0;
            }else{
                ll wait = t-k;
                if(wait < last_free){
                    ans = wait;
                    last_free = wait;
                }
            }
            break;
        }
        if(arr[i] >= t){
            last_free = 0;
            ans = 0;
        }else{
            ll wait = t-arr[i];
            if(wait < last_free){
                ans = wait;
                last_free = wait;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}