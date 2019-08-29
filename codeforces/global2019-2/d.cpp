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
V<ll> a;
ll binary_search(ll k){
    ll low = 1;
    ll high = a.size()-1;
    ll ans = 0;
    while(low <= high){
        ll mid = (low + high)/2;
        if(a[mid] == k && a[mid+1] > k)return mid;
        if(a[mid] > k && a[mid-1] < k)return mid-1;
        if(a[mid] < k && a[mid+1] > k)return mid;
        if(a[mid] > k){
            high = mid-1;
        }else{
            low = mid+1;
            ans = mid;
        }
    }
    return ans;
}

int main(){
    FAST
    int n,q;
    cin >> n;
    set<ll> s;
    loop(i,0,n){
        ll a;
        cin >> a;
        s.insert(a);
    }
    V<ll> arr;
    for(auto i: s){
        arr.pb(i);
    }
    a = V<ll> (arr.size()+1,LLONG_MIN);
    a[arr.size()] = LLONG_MAX;
    V<ll> pref(arr.size()+1,0);
    for(int i = 0; i+1 < arr.size(); ++i){
        a[i+1] = arr[i+1]-arr[i];
    }
    sort(a.begin(),a.end());
    loop(i,1,a.size()-1){
        pref[i] += (a[i] + pref[i-1]);
    }
    // loop(i,1,a.size()-1){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cin >> q;
    while(q--){
        ll b,c;
        cin >> b >> c;
        ll k = abs(b-c) + 1;
        ll i = binary_search(k);
        ll ans = k + pref[i] + (a.size()-2-i)*k;
        // printf("k = %lld, i = %lld, pref[i] = %lld, (a.size() - 2)*k = %lld\n",k,i,pref[i],(a.size()-2)*k);
        cout << ans << " ";
    }

    return 0;
}