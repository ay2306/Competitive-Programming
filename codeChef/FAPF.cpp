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
    int n,q;
    cin >> n >> q;
    V<PLL> arr(n);
    V<ll> arr1(n);
    loop(i,0,n){
        cin >> arr[i].F;
        arr1[i] = arr[i].F;
        arr[i].S = i;
    }
    sort(arr.begin(),arr.end());
    unordered_map<ll,ll> mn;
    unordered_map<ll,ll> mx;
    loop(i,0,n){
        if(mx.find(arr[i].F) == mx.end())mx[arr[i].F] = i;
        else mx[arr[i].F] = max(mx[arr[i].F],i*1LL);
        if(mn.find(arr[i].F) == mn.end())mn[arr[i].F] = i;
        else mn[arr[i].F] = min(mn[arr[i].F],i*1LL);
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cout << abs(arr1[a]-arr1[b]) + b - a;
        cout << " ";
        ll mna = min(mn[arr1[a]],mn[arr1[b]]);
        ll mxa = max(mx[arr1[a]],mx[arr1[b]]);
        cout << mxa-mna + 1 << "\n";
    }
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}