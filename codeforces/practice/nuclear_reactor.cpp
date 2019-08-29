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
ll n;
int k;
V<ll> arr;

bool check(ll dist){
    ll prev = arr[0];
    int ct = 1;
    for(int i = 1; i < n; ++i){
        if(arr[i]-prev >= dist){
            ct++;
            prev = arr[i];
        }
    }
    if(ct < k)return false;
    return true;
}

int main(){
    cin >> n >> k;
    arr = V<ll> (n);
    loop(i,0,n){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll low = 0;
    ll high = 1e18;
    ll ans = 0;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(mid)){
            low = mid+1;
            ans = max(ans,mid);
        }else{
            high = mid-1;
        }
    }
    V<ll> a;
    a.pb(arr[0]);
    for(int i = 1; i < n; ++i){
        if(arr[i] - *a.rbegin() >= ans){
            a.pb(arr[i]);
        }
        if(a.size() == k)break;
    }
    for(auto i: a){
        cout << i << " ";
    }
    return 0;
}