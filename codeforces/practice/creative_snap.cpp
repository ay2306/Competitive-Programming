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

V<ll> arr;
ll n,k,a,b;

ll power(ll l, ll r){
    // cout << l <<  " " << r << "\n";
    ll i=lower_bound(arr.begin(),arr.end(),l)-arr.begin();
	ll j=upper_bound(arr.begin(),arr.end(),r)-arr.begin();
	j--;
	long long av=j-i+1;
    long long p = 0;
    if(av == 0)p = a;
    else{
        p = av*(r-l+1)*b;
    }
    if(l == r || av == 0)return p;
    ll mid = (l+r)/2;
    p = min(p,power(l,mid)+power(mid+1,r));
    return p;
}


int main(){
    cin >> n >> k >> a >> b;
    arr = V<ll> (k);
    loop(i,0,k){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans = power(1,(1LL << n));
    cout << ans;
    return 0;
}