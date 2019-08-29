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

int main(){
    ll n,l;
    cin >> n >> l;
    V<ll> arr(40);
    loop(i,0,n){
        cin >> arr[i];
    }
    loop(i,1,n){
        if(2*arr[i-1] < arr[i])arr[i] = 2*arr[i-1];
    }
    loop(i,n,31){
        arr[i] = 2*arr[i-1];
    }
    ll ans = 0;
    ll op = l;
    for(int i = 0; i <= 30 && l; ++i){
        // cout << l << " ";
        if(l%2){
            // cout << i << " " << arr[i];
            ans+=arr[i];
        }
        // cout << endl;
        l/=2;
    }
    l = op;
    loop(i,0,31){
        ll a = 1;
        if((a << i) >= l){
            ans = min(ans,arr[i]);
        }
    }
    cout << ans;
    return 0;
}